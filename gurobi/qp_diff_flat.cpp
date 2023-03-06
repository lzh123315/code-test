#include "gurobi_c++.h"
#include <vecotr>

std::vector<double> first_problem_solution(GRBEnv *env,
int n_of_p,
double *lb_p,
std::vector<double> initial_p,
std::vector<double> initial_z,
std::vector<double> lamda,
std::vector<std::vector<double>> A_eq,
std::vector<double> b_eq,
std::vector<std::vector<double>> Q,
std::vector<std::vector<double>> S,
double sida)
{
   std::vector<double> solution;
          // Build the Model
    GRBModel first_problem = GRBModel(env);
    double initial_p_array[initial_p.size()];
    mempcpy(initial_p_array, &initial_p[0], initial_p.size() * sizeof(initial_p[0]));
    GRBVar *p = first_problem.addVars(lb_p, NULL, initial_p_array, NULL, NULL, n_of_p);
    for (size_t i = 0; i < A_eq.size(); i++)

    {
        RBLinExpr lhs = 0;
        for (size_t j = 0; j < A_eq.front().size(); j++)

        {
        f (A_eq[i][j] != 0)

            {
                lhs += A_eq[i][j] * p[j];
          
            }
     
        }
    first_problem.addConstr(lhs, GRB_EQUAL, b_eq[i]);

    }

          // objective function
    GRBQuadExpr obj = 0;
    obj += sida / 2 * (S[0][0] * p[0] * S[0][0] * p[0] - 2 * S[0][0] * p[0] * (initial_z[0] - lamda[0] / sida));
    obj += sida / 2 * (S[1][1] * p[1] * S[1][1] * p[1] - 2 * S[1][1] * p[1] * (initial_z[1] - lamda[1] / sida));
    obj += sida / 2 * (S[2][2] * p[2] * S[2][2] * p[2] - 2 * S[2][2] * p[2] * (initial_z[2] - lamda[2] / sida));
    for (size_t i = 3; i < S.size(); i++)
    {
         for (size_t j = (i - 3) / 15 * 6; j < ((i - 3) / 15 + 1) * 6; j++)
        {
            obj += sida / 2 * (-2 * S[i][j] * p[j] * (initial_z[i] - lamda[i] / sida));
            for (size_t k = (i - 3) / 15 * 6; k < ((i - 3) / 15 + 1) * 6; k++)
        }
    }