import sympy as sy


p0, p1, p2, p3, p4, p5, t = sy.symbols('p0 p1 p2 p3 p4 p5 t')
f = p5 * (t ** 5) + p4 * (t ** 4) + p3 * (t ** 3) + p2 * (t ** 2) + p1 * t + p0
f3 = sy.diff(f, t, t, t)
print(f'f3: {f3}')
sq_f3 = f3 * f3
esq_f3 = sy.expand(sq_f3)
print(f'ef3_sq:{esq_f3}')
cost = sy.integrate(esq_f3, t)
print(f'cost: {sy.expand(cost)}')