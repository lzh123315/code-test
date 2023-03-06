// 这个工程用来优化 y = e ^ (m*x + c)中的m和c参数
#include <ceres/ceres.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <vector>

// 一个仿函数用于设置残差计算
class ExpResidual
{
public:
    ExpResidual(double x, double y) : x_(x), y_(y) {}

    // 残差计算
    // 注意残差计算operator后边是先优化变量再残差，和AutoDiff中相反
    template <typename T>
    bool operator()(const T *m, const T *c, T *residual) const
    {
        residual[0] = T(y_) - ceres::exp(m[0] * T(x_) + c[0]);
        return true;
    }

    const double x_;
    const double y_;
};

int main()
{
    double m = 0.0, c = 0.0;
    cv::RNG rng;
    double w_sigma = 0.2;

    ceres::Problem problem; // 1. 建立一个最小二乘问题
    for (int i = 0; i < 100; ++i)
    {
        // 我们按照m = 0.3, c = 0.1来对100个点进行赋值，并给予白噪声
        double y_with_noise =
            std::exp(0.3 * i / 100.0 + 0.1) + rng.gaussian(w_sigma * w_sigma);
        // 2. 建立一个CostFunction, 如果是AutoDiff自动求解就如下
        // AutoDiffCostFunction<仿函数类，残差的维度，剩下的一堆是优化变量的维度>
        ceres::CostFunction *cost_function =
            new ceres::AutoDiffCostFunction<ExpResidual, 1, 1, 1>(
                new ExpResidual(i / 100.0, y_with_noise));
        // 3. 添加残差模块，用problem.AddResidualBlock(costFunc, 鲁邦核函数，优化变量们用指针传)
        problem.AddResidualBlock(cost_function, new ceres::CauchyLoss(0.5), &m, &c);
    }

    // 4. 设置求解器和输出报告
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_NORMAL_CHOLESKY;
    options.minimizer_progress_to_stdout = true;

    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    std::cout << summary.BriefReport() << std::endl;
    std::cout << "m = " << m << " c = " << c << std::endl;
    return 0;
}
