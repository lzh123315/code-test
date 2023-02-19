#include <cmath>
#include <random>
#include <eigen3/Eigen/Core>
#include <nlopt.hpp>
#include <iostream>
#include <mgl2/fltk.h>


//编译 g++ norm_test.cpp -lnlopt -lm

//别用auto 对random的类型进行自动推导

//don not use the gradient
bool grad_bool = 0;
double objFunc(const std::vector<double>& x, std::vector<double>& grad, void* f_data){
    double result = 0.0;
    if (grad_bool);
    for (double num : x){
        result += std::abs(num);
    }
    return result;
}

typedef struct {
    Eigen::VectorXd Ai;
    double bi;
}Constrain;


double eqConstrain(const std::vector<double>& x, std::vector<double>& grad, void* f_data){
    Constrain *p = static_cast<Constrain*>(f_data);
    double product = 0;
    if (grad_bool);
    for (int i = 0; i < x.size(); ++i){
        product += x[i] * p->Ai[i];
    }
    return product - p->bi;  
}

int main(){
    int m = 128, n = 256;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::normal_distribution<> dist;
    std::uniform_int_distribution<int> zero_pos_gen(0, 255);
    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(128, 256).unaryExpr([&](double dummy){return dist(gen);});
    // std::cout << "Gussian Matrix:" << std::endl;
    // std::cout << A.row(0) << std::endl;
    // std::cout << A.rows() << std::endl;

    std::vector<int> zero_pos_vec;
    for (int i = 0; i < (n - n / 10); ++i){
        zero_pos_vec.push_back(zero_pos_gen(gen));
    }
    Eigen::VectorXd u = Eigen::VectorXd::Zero(n,1).unaryExpr([&](double dummy){return dist(gen);});
    for (auto num : zero_pos_vec){
        u[num] = 0;
    }
    // std::cout << "Sparse Vecotr:" << std::endl;
    // std::cout << u << std::endl;

    auto b = A * u;
    // std::cout << "Result A * u:" << std::endl;
    // std::cout << b << std::endl;

    mglGraph gr;
    gr.Title("MathGL Demo");
    gr.SetOrigin(0, 0);
    gr.SetRanges(0, 279, -10, 10);
    std::vector<double> y_vec(u.data(), u.data() + n);
    mglData y(y_vec);
    gr.Plot(y, "r-2");
    gr.Axis();
    gr.Grid();
    gr.WriteFrame("mgl_example.png");

    // std::cout << "Result constrain:" << std::endl;
    Constrain c[128];
    for (int i = 0; i < m; ++i){
        c[i].Ai = A.row(i);
        c[i].bi = b(i);
    }
    // std::cout << c[0].Ai << std::endl;
    // std::cout << b(0) << std::endl;

    auto opter = nlopt::opt(nlopt::GN_ISRES, n);

    std::vector<double> lb(n, -10);
    std::vector<double> ub(n, 10);
    opter.set_lower_bounds(lb);
    opter.set_upper_bounds(ub);

    //设置优化精度
	double tol = 1e-4;              //容差
    opter.set_xtol_rel(tol);
    opter.set_force_stop(tol);

    opter.set_min_objective(objFunc, NULL);
 
    for (int i = 0; i < m; ++i){
        opter.add_equality_constraint(eqConstrain, &c[i], tol);
    }

    double f_min = 10000;
    
    std::vector<double> x(256);
    nlopt::result res = opter.optimize(x, f_min);

}