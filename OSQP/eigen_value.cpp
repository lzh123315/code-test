#include <cmath>
#include <Eigen/Dense>
#include <iostream>

int main()
{
    double t = 50 * 0.1;
    auto t_sq = t * t, t_cub = t_sq * t, t_quar = t_cub * t, t_quin = t_quar * t;
    Eigen::MatrixXd m(6, 6);
    m << 0, 0, 0, 0, 0, 1,                            //
        0, 0, 0, 0, 1, 0,                             //
        0, 0, 0, 2, 0, 0,                             //
        t_quin, t_quar, t_cub, t_sq, t, 1,            //
        5 * t_quar, 4 * t_cub, 3 * t_sq, 2 * t, 1, 0, //
        20 * t_cub, 12 * t_sq, 6 * t, 2, 0, 0;
    auto inv_m = m.inverse();
    Eigen::MatrixXd jm(6, 6), j(12, 12);
    jm << 720 * t_quin, 720 * t_quar, 240 * t_cub, 0, 0, 0, //
        0, 192 * t_cub, 144 * t_sq, 0, 0, 0,                //
        0, 0, 36 * t, 0, 0, 0,                              //
        0, 0, 0, 0.001, 0, 0,                               //
        0, 0, 0, 0, 0.001, 0,                               //
        0, 0, 0, 0, 0, 0.001;
    j.block(0, 0, 6, 6) = jm;
    j.block(6, 6, 6, 6) = jm;

    std::cout << "inverse m:" << std::endl;
    std::cout << inv_m << std::endl;

    std::cout << "j:" << std::endl;
    std::cout << j.eigenvalues() << std::endl;

    std::cout << "hessian:" << std::endl;
    auto h = inv_m.transpose() * jm * inv_m;
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(h);
    std::cout << eigensolver.eigenvalues() << std::endl;
    std::cout << h.eigenvalues() << std::endl;
}