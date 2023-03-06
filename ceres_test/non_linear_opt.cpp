#include <ceres/ceres.h>
#include <iostream>
#include <vector>

struct CostFunc
{
    template <typename T>
    bool operator()(const T *param, T *cost) const
    {
        const T x = param[0];
        if (x > 0.0)
        {
            cost[0] = T{0.0};
        }
        else
        {
            cost[0] = x * x + x;
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    double param[2] = {-8, 0};
    ceres::FirstOrderFunction *function = new ceres::AutoDiffFirstOrderFunction<CostFunc, 2>(new CostFunc);
    ceres::GradientProblem problem(function);
    ceres::GradientProblemSolver::Options options;
    options.minimizer_progress_to_stdout = true;
    ceres::GradientProblemSolver::Summary summary;
    ceres::Solve(options, problem, param, &summary);

    std::cout << "ans: " << param[0] << std::endl;
    std::cout << summary.FullReport() << std::endl;
    return 0;
}