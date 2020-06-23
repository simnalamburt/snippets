import numpy as np
min, max = -0.8777435, 0.57090986

M = np.asmatrix([
    [0.02355068, -0.50542802, 0.16642167, -0.44872788, -0.05130898, 0.13320047, 0.41464597, -0.55703336, 0.52567458, 0.23784444, 0.15049535, 0.16599870, -0.28757980, 0.22277315, 0.56460077, -0.70838273, -0.61990398, -0.39724344, -0.09969769, 0.45835119, 0.02840372, 0.09637213, 0.04063996, -0.16667950, -0.68209213, -0.09524837, 0.27514741, 0.02957204, -0.11251312, -0.43414843],
    [-0.31239739, -0.13213386, -0.59719753, -0.16117097, 0.29835659, -0.21633907, -0.55013347, -0.22406115, -0.47912723, -0.08179668, 0.46718585, 0.38543564, -0.49470344, -0.35172677, -0.23060481, -0.39899889, -0.18135746, -0.54352880, -0.28287631, -0.05576789, 0.20255803, 0.18899839, 0.36582524, 0.43294433, 0.21794824, -0.62954980, -0.52842420, 0.00261285, 0.23226254, 0.27430296],
    [-0.12496945, 0.27272177, 0.09565081, -0.19869098, 0.40514281, 0.30038768, -0.13575996, -0.01735646, 0.31392211, -0.34690821, -0.26467761, 0.27735108, 0.25757775, 0.56070799, 0.48236406, -0.16126287, -0.56543708, -0.52047604, 0.31337339, 0.31964961, -0.19712290, 0.29141095, 0.25103137, -0.49437916, -0.00175839, -0.39314604, -0.46974984, -0.24069642, -0.07134162, 0.38584659],
    [-0.22494942, -0.23908727, -0.14118181, 0.25917593, -0.46544874, 0.21652603, 0.11955780, -0.08858330, 0.11210553, 0.15425776, 0.35051644, 0.12857421, -0.31161663, -0.10459967, 0.28051424, 0.35245281, 0.21058421, -0.38336727, -0.53721315, -0.45408809, 0.17018577, 0.37464410, 0.25320616, -0.50858176, 0.03510477, 0.28646398, -0.49693882, 0.31466347, 0.34066224, 0.39151987],
    [-0.24122262, -0.18464386, -0.50166339, -0.06581594, 0.23343681, -0.28764677, -0.28263095, 0.47374201, -0.14122090, 0.41170570, -0.27171388, -0.76247406, -0.43367779, -0.41885039, -0.58815128, 0.16303478, -0.15360811, 0.40358800, 0.28507465, 0.11577206, -0.05193469, 0.10712312, 0.37356687, 0.17525157, -0.61338550, 0.28956139, 0.04172062, 0.19050168, -0.36498675, -0.48431775],
    [0.20951799, -0.57114357, 0.16709965, 0.28986153, -0.48571789, 0.17514014, 0.42663154, -0.58854365, -0.49951825, -0.69118619, -0.12997085, 0.20892869, -0.27441102, 0.25154045, 0.33150116, 0.22571780, 0.00198699, -0.21132891, 0.54626226, -0.39937377, 0.09991331, 0.16465400, -0.31479383, 0.19637901, 0.27371463, -0.35296553, 0.32819411, 0.33079246, 0.09111243, -0.15263695],
    [0.23110701, -0.82688808, 0.35345000, -0.63799143, 0.10259465, -0.67562747, 0.06791017, -0.55785728, 0.11328468, 0.03148035, 0.06963930, -0.40473521, 0.15695126, 0.10480986, 0.06786098, 0.05529213, -0.06358500, 0.39808711, -0.46259707, -0.41053730, 0.23919414, 0.06440434, -0.55259717, 0.17278855, -0.26870996, -0.59644037, -0.20437278, -0.15572956, -0.62037915, 0.20436110],
    [0.43668377, 0.03184615, -0.79770166, 0.30957624, -0.29246098, 0.41470772, -0.39726156, 0.08003121, 0.32232824, 0.18267424, -0.46286914, -0.52988207, 0.40305007, 0.43693665, 0.57090986, -0.71393168, 0.16701773, -0.01028878, 0.03239791, -0.39907083, 0.20838976, 0.25748143, 0.24718748, -0.05084279, -0.52348840, -0.07115566, -0.33007148, 0.18890919, 0.40487564, 0.28275076],
    [0.00545317, 0.05541809, -0.29821581, -0.69852740, 0.23890208, -0.58182591, 0.37835562, -0.12874492, -0.24086623, -0.18621640, 0.20001458, -0.55234039, 0.40093267, 0.19279823, -0.56214923, -0.12595257, -0.13790886, 0.04751531, -0.31666499, 0.33546147, 0.19133377, 0.01450487, -0.69050521, -0.15352796, 0.31702802, 0.13524684, 0.08716883, 0.35998338, 0.36140910, -0.18685688],
    [0.13561521, 0.09853959, 0.23551922, -0.37978131, -0.26070073, 0.43132550, -0.10494933, 0.07914228, 0.04663205, -0.41666678, 0.16825140, 0.51182604, 0.13776678, -0.68972874, -0.72430468, -0.10668162, 0.29812980, -0.13480635, -0.66627938, 0.01717626, -0.11104345, 0.31376141, 0.39751169, -0.19769318, -0.28220543, 0.13042673, 0.42700538, 0.08965667, 0.18087055, -0.87774348],
])

S = (max - min)/127.0
result = np.clip(np.ceil(M/S).astype(int), -128, 127).tolist()

print(
    '\n'.join(
        ' '.join(str(e) for e in row)
        for row in result
    )
)