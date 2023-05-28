#include "highpassfilter_cofficient.h"

highpassfilter_pDelayLinkList highpassfilter_pDelay[8];     // 用于存储每个通道过去时刻滤波后的结果
bool HighPassFilterStatus = false;                          // FIR高通滤波状态标志
uint16_t FIR_Highpassfilter_FilterLength = 921;             // FIR高通滤波器阶数
double   FIR_Highpassfilter_Coefficient[921] =              // FIR高通滤波器权重系数
{
    -1.25195397101e-09,-1.281303376423e-09,-1.218499392545e-09,-1.043417026393e-09,
    -7.346074495739e-10,-2.694595974458e-10,3.756018388686e-10,1.224880810778e-09,
      2.3031358399e-09,3.635267011282e-09,5.245964004573e-09,7.159315609669e-09,
    9.398381682355e-09,1.198472903689e-08,1.493793334217e-08,1.827504968272e-08,
    2.201005505932e-08,2.615326673332e-08,3.071074095525e-08, 3.56836572588e-08,
    4.106769413593e-08,4.685240253346e-08,5.302058421579e-08,5.954768261654e-08,
    6.640119434429e-08,7.354011000697e-08,8.091439346571e-08,8.846450901601e-08,
    9.612100630977e-08,1.038041730719e-07,1.114237658173e-07,1.188788288326e-07,
    1.260576116465e-07,1.328375950572e-07,1.390856355234e-07, 1.44658237333e-07,
     1.49401961455e-07,1.531539793319e-07, 1.55742779097e-07,1.569890307867e-07,
    1.567066160718e-07,1.547038268493e-07,1.507847357178e-07,1.447507399137e-07,
    1.364022787155e-07,1.255407226258e-07,1.119704308432e-07, 9.55009716263e-08,
    7.594949815426e-08,5.314327041678e-08,2.692231151672e-08,-2.857815413658e-09,
    -3.63231257122e-08,-7.357824536324e-08,-1.147033773472e-07,-1.597512248612e-07,
    -2.087438962657e-07,-2.616698186936e-07,-3.184806892494e-07,-3.790884945852e-07,
    -4.43362631373e-07,-5.111271617299e-07,-5.821582390192e-07,-6.561817405742e-07,
    -7.328711447849e-07,-8.118456905982e-07, -8.9266885781e-07,-9.748472065307e-07,
    -1.057829613882e-06,-1.141006945285e-06,-1.223712196663e-06,-1.305221142414e-06,
    -1.384753522182e-06,-1.461474797188e-06,-1.534498504222e-06,-1.602889232294e-06,
    -1.66566624344e-06,-1.721807755253e-06,-1.770255898354e-06,-1.809922357297e-06,
    -1.839694698286e-06,-1.858443381571e-06,-1.865029450595e-06,-1.858312883801e-06,
     -1.8371615886e-06,-1.800461010331e-06,-1.747124322166e-06,-1.676103154897e-06,
    -1.586398818377e-06,-1.477073959194e-06,-1.347264591949e-06,-1.196192434337e-06,
    -1.023177469212e-06,-8.276506499086e-07,-6.091666585516e-07,-3.674166206794e-07,
    -1.022406736825e-07,1.863597189845e-07,4.982098207634e-07,8.329501594459e-07,
    1.190025670121e-06,1.568675567601e-06,1.967924074433e-06,2.386572131977e-06,
    2.823190222353e-06,3.276112428547e-06,3.743431858291e-06,4.222997554721e-06,
    4.712413012994e-06,5.209036417136e-06, 5.70998270529e-06,6.212127564293e-06,
    6.712113445977e-06,7.206357687999e-06,7.691062811072e-06,8.162229052534e-06,
    8.615669182945e-06,9.047025638198e-06,9.451789984276e-06,9.825324715501e-06,
    1.016288736984e-05,1.045965692681e-05,1.071076243461e-05,1.091131379374e-05,
    1.105643460415e-05, 1.11412969628e-05,1.116115807743e-05,1.111139854181e-05,
    1.098756209662e-05, 1.07853966795e-05,1.050089654733e-05,1.013034523403e-05,
    9.670359087703e-06,9.117931112671e-06,8.470474824467e-06,7.725867809676e-06,
    6.882494667529e-06,5.939288997055e-06,4.895774081742e-06,3.752101914263e-06,
     2.50909019587e-06,1.168256939968e-06,-2.68147693989e-07,-1.797112710393e-06,
    -3.414841103421e-06,-5.116728566267e-06,-6.897346443335e-06,-8.750429274352e-06,
    -1.066886726586e-05,-1.264470400862e-05,-1.46691397402e-05,-1.67325404284e-05,
    -1.882445292626e-05,-2.09336264194e-05,-2.304804035553e-05,-2.515493901019e-05,
    -2.724087280603e-05,-2.929174646215e-05,-3.129287400755e-05,-3.322904064735e-05,
    -3.508457142398e-05,-3.684340656561e-05,-3.848918336424e-05,-4.000532437334e-05,
    -4.137513166232e-05,-4.258188681097e-05,-4.360895627331e-05,-4.443990168575e-05,
    -4.505859464089e-05,-4.544933539516e-05,-4.55969749267e-05,-4.548703970894e-05,
    -4.510585851781e-05,-4.444069054344e-05,-4.347985403471e-05,-4.221285466426e-05,
    -4.063051276577e-05,-3.872508856221e-05,-3.649040447623e-05,-3.392196359045e-05,
    -3.101706330729e-05,-2.777490324557e-05,-2.419668640449e-05,-2.028571262468e-05,
    -1.604746338236e-05,-1.148967696459e-05,-6.622413093415e-06,-1.45810609247e-06,
    3.988394276566e-06,9.699795139872e-06,1.565634678417e-05,2.183584360561e-05,
    2.821364040185e-05,3.476268460585e-05,4.145356498288e-05,4.825457723075e-05,
    5.513180683311e-05,6.204922942166e-05,6.896882880168e-05, 7.58507326897e-05,
    8.265336610148e-05,8.933362221366e-05,9.584705040331e-05,0.0001021480610497,
    0.0001081901465563,0.0001139261179291,0.0001193083561163,0.0001242890771936,
    0.0001288206103493,0.0001328556875006,0.0001363477432527,0.0001392512237918,
    0.0001415219031888, 0.000143117205485,0.0001439965308228,0.0001441215837938,
    0.0001434567020839,0.0001419691834175,0.0001396296087343,0.0001364121594668,
    0.0001322949267451,0.0001272602103113,0.0001212948049063,0.0001143902718773,
    0.0001065431937576,9.775540958425e-05,8.803422875372e-05,7.739262125574e-05,
    6.584938219058e-05,5.342926854817e-05,4.016310631947e-05,2.608786611667e-05,
    1.124670560067e-05,-4.311022848976e-06,-2.052980063627e-05,-3.734800886964e-05,
     -5.4698032772e-05,-7.250640545481e-05,-9.069399172887e-05,-0.0001091762124061,
    -0.0001278633093212,-0.0001466606510651,-0.0001654690791756,-0.0001841852942828,
    -0.0002027022814427,-0.0002209097736356,-0.0002386947521368,-0.0002559419822011,
    -0.0002725345822357, -0.00028835462437,-0.0003032837640692,-0.000317203896182,
    -0.0003299978345618,-0.0003415500121595,-0.0003517471982546,-0.0003604792292721,
    -0.0003676397494285,-0.0003731269572564,-0.0003768443538899,-0.0003787014888334,
    -0.0003786146988064,-0.0003765078351425,-0.0003723129751324,-0.000365971112637,
    -0.0003574328232539,-0.0003466588993129,-0.0003336209499871,-0.0003183019618501,
    -0.0003006968152828,-0.0002808127522322,-0.0002586697909592,-0.0002343010835682,
    -0.0002077532123058,-0.0001790864208339,-0.0001483747769311,-0.0001157062633558,
    -8.118279390846e-05,-4.492015206079e-05,-7.047849883402e-06,3.229109462269e-05,
    7.294046327223e-05,0.0001147312275814,0.0001574820234053,0.0002009997104787,
    0.0002450800165352,0.0002895082651864, 0.000334060186245,0.0003785028066693,
    0.0004225954197866,0.0004660906299491,0.0005087354692511,0.0005502725824347,
    0.0005904414756027,0.0006289798238683,0.0006656248325882,0.0007001146463643,
    0.0007321897995544, 0.000761594701612,0.0007880791501742,0.0008113998644582,
    0.0008313220311798,0.0008476208549141,0.0008600831045472,0.0008685086472451,
    0.0008727119611775,0.0008725236180983,0.0008677917267822,0.0008583833282769,
    0.0008441857339229,0.0008251077971504,0.0008010811101606,0.0007720611167556,
    0.0007380281327846,0.0006989882659343,0.0006549742269037,0.0006060460243635,
    0.0005522915365167, 0.000493826952543,0.0004307970777179,0.0003633754965638,
    0.0002917645889918, 0.000216195395045,0.0001369273245385,5.424770862572e-05,
    -3.152880892786e-05,-0.0001200610421805,-0.0002109821957643,-0.0003039009597051,
    -0.0003984027652109,-0.0004940511994416,-0.0005903895763914,-0.0006869426601145,
    -0.0007832185356318,-0.0008787106219587,-0.0009728998208144,-0.001065256793697,
    -0.001155244359155,-0.001242320001265,-0.001325938479505,-0.001405554529466,
    -0.001480625643097,-0.001550614916502,-0.001614993952663,-0.001673245805876,
    -0.001724867954149,-0.001769375285359,-0.001806303082532, -0.00183520999328,
    -0.001855680968176,-0.001867330152619,-0.001869803716647, -0.00186278260711,
    -0.001845985206631,-0.001819169883944,-0.001782137420349,-0.001734733297347,
    -0.001676849830871,-0.001608428137965,-0.001529459922322,-0.001439989065668,
    -0.001340113012704,-0.001229983938048,-0.001109809684492,-0.0009798544627676,
    -0.0008404393040197,-0.0006919422571991,-0.000534798324711,-0.0003694991307891,
    -0.0001965923182782,-1.668067074859e-05,0.0001695790418443,0.0003614774944361,
    0.0005582545141929,0.0007591010616917,0.0009631614823375, 0.001169536023045,
     0.001377283607824, 0.001585424864547, 0.001792945393826, 0.001998799269589,
     0.002201912759656, 0.002401188253344,  0.00259550838192, 0.002783740316544,
     0.002964740227253, 0.003137357885475, 0.003300441391586, 0.003452842008155,
     0.003593419078661, 0.003721045010777, 0.003834610302665, 0.003933028590179,
     0.004015241692442, 0.004080224632941, 0.004126990613031, 0.004154595914636,
     0.004162144708932,   0.0041487937479,  0.00411375691585, 0.004056309618364,
     0.003975792986545, 0.003871617875033, 0.003743268632896, 0.003590306627322,
     0.003412373500891, 0.003209194144217, 0.002980579366834, 0.002726428250389,
     0.002446730169467, 0.002141566466756, 0.001811111770667, 0.001455634945061,
      0.00107549966229,0.0006711645924106, 0.000243183203085,-0.0002077968335548,
    -0.0006810346290783, -0.00117569746215,-0.001690862555548,-0.002225519243378,
    -0.002778571523265,-0.003348840986486,-0.003935070117229,-0.004535925950405,
    -0.005150004075732,-0.005775832974102,-0.006411878670676,-0.007056549687521,
    -0.007708202277183, -0.00836514591712,-0.009025649043637,-0.009687945002692,
     -0.01035023819384, -0.01101071038253, -0.01166752715503, -0.01231884448952,
     -0.01296281541613, -0.01359759673816, -0.01422135578635, -0.01483227717769,
     -0.01542856955001, -0.01600847224391, -0.01657026190314, -0.01711225896531,
     -0.01763283401474, -0.01813041397016, -0.01860348808019, -0.01905061370063,
     -0.01947042182835, -0.01986162236738, -0.02022300910437, -0.02055346437132,
     -0.02085196337517, -0.02111757817515, -0.02134948129023, -0.02154694892083,
     -0.02170936377048, -0.02183621745487, -0.02192711248768, -0.02198176383433,
       0.9780000011899, -0.02198176383433, -0.02192711248768, -0.02183621745487,
     -0.02170936377048, -0.02154694892083, -0.02134948129023, -0.02111757817515,
     -0.02085196337517, -0.02055346437132, -0.02022300910437, -0.01986162236738,
     -0.01947042182835, -0.01905061370063, -0.01860348808019, -0.01813041397016,
     -0.01763283401474, -0.01711225896531, -0.01657026190314, -0.01600847224391,
     -0.01542856955001, -0.01483227717769, -0.01422135578635, -0.01359759673816,
     -0.01296281541613, -0.01231884448952, -0.01166752715503, -0.01101071038253,
     -0.01035023819384,-0.009687945002692,-0.009025649043637, -0.00836514591712,
    -0.007708202277183,-0.007056549687521,-0.006411878670676,-0.005775832974102,
    -0.005150004075732,-0.004535925950405,-0.003935070117229,-0.003348840986486,
    -0.002778571523265,-0.002225519243378,-0.001690862555548, -0.00117569746215,
    -0.0006810346290783,-0.0002077968335548, 0.000243183203085,0.0006711645924106,
      0.00107549966229, 0.001455634945061, 0.001811111770667, 0.002141566466756,
     0.002446730169467, 0.002726428250389, 0.002980579366834, 0.003209194144217,
     0.003412373500891, 0.003590306627322, 0.003743268632896, 0.003871617875033,
     0.003975792986545, 0.004056309618364,  0.00411375691585,   0.0041487937479,
     0.004162144708932, 0.004154595914636, 0.004126990613031, 0.004080224632941,
     0.004015241692442, 0.003933028590179, 0.003834610302665, 0.003721045010777,
     0.003593419078661, 0.003452842008155, 0.003300441391586, 0.003137357885475,
     0.002964740227253, 0.002783740316544,  0.00259550838192, 0.002401188253344,
     0.002201912759656, 0.001998799269589, 0.001792945393826, 0.001585424864547,
     0.001377283607824, 0.001169536023045,0.0009631614823375,0.0007591010616917,
    0.0005582545141929,0.0003614774944361,0.0001695790418443,-1.668067074859e-05,
    -0.0001965923182782,-0.0003694991307891,-0.000534798324711,-0.0006919422571991,
    -0.0008404393040197,-0.0009798544627676,-0.001109809684492,-0.001229983938048,
    -0.001340113012704,-0.001439989065668,-0.001529459922322,-0.001608428137965,
    -0.001676849830871,-0.001734733297347,-0.001782137420349,-0.001819169883944,
    -0.001845985206631, -0.00186278260711,-0.001869803716647,-0.001867330152619,
    -0.001855680968176, -0.00183520999328,-0.001806303082532,-0.001769375285359,
    -0.001724867954149,-0.001673245805876,-0.001614993952663,-0.001550614916502,
    -0.001480625643097,-0.001405554529466,-0.001325938479505,-0.001242320001265,
    -0.001155244359155,-0.001065256793697,-0.0009728998208144,-0.0008787106219587,
    -0.0007832185356318,-0.0006869426601145,-0.0005903895763914,-0.0004940511994416,
    -0.0003984027652109,-0.0003039009597051,-0.0002109821957643,-0.0001200610421805,
    -3.152880892786e-05,5.424770862572e-05,0.0001369273245385, 0.000216195395045,
    0.0002917645889918,0.0003633754965638,0.0004307970777179, 0.000493826952543,
    0.0005522915365167,0.0006060460243635,0.0006549742269037,0.0006989882659343,
    0.0007380281327846,0.0007720611167556,0.0008010811101606,0.0008251077971504,
    0.0008441857339229,0.0008583833282769,0.0008677917267822,0.0008725236180983,
    0.0008727119611775,0.0008685086472451,0.0008600831045472,0.0008476208549141,
    0.0008313220311798,0.0008113998644582,0.0007880791501742, 0.000761594701612,
    0.0007321897995544,0.0007001146463643,0.0006656248325882,0.0006289798238683,
    0.0005904414756027,0.0005502725824347,0.0005087354692511,0.0004660906299491,
    0.0004225954197866,0.0003785028066693, 0.000334060186245,0.0002895082651864,
    0.0002450800165352,0.0002009997104787,0.0001574820234053,0.0001147312275814,
    7.294046327223e-05,3.229109462269e-05,-7.047849883402e-06,-4.492015206079e-05,
    -8.118279390846e-05,-0.0001157062633558,-0.0001483747769311,-0.0001790864208339,
    -0.0002077532123058,-0.0002343010835682,-0.0002586697909592,-0.0002808127522322,
    -0.0003006968152828,-0.0003183019618501,-0.0003336209499871,-0.0003466588993129,
    -0.0003574328232539,-0.000365971112637,-0.0003723129751324,-0.0003765078351425,
    -0.0003786146988064,-0.0003787014888334,-0.0003768443538899,-0.0003731269572564,
    -0.0003676397494285,-0.0003604792292721,-0.0003517471982546,-0.0003415500121595,
    -0.0003299978345618,-0.000317203896182,-0.0003032837640692, -0.00028835462437,
    -0.0002725345822357,-0.0002559419822011,-0.0002386947521368,-0.0002209097736356,
    -0.0002027022814427,-0.0001841852942828,-0.0001654690791756,-0.0001466606510651,
    -0.0001278633093212,-0.0001091762124061,-9.069399172887e-05,-7.250640545481e-05,
     -5.4698032772e-05,-3.734800886964e-05,-2.052980063627e-05,-4.311022848976e-06,
    1.124670560067e-05,2.608786611667e-05,4.016310631947e-05,5.342926854817e-05,
    6.584938219058e-05,7.739262125574e-05,8.803422875372e-05,9.775540958425e-05,
    0.0001065431937576,0.0001143902718773,0.0001212948049063,0.0001272602103113,
    0.0001322949267451,0.0001364121594668,0.0001396296087343,0.0001419691834175,
    0.0001434567020839,0.0001441215837938,0.0001439965308228, 0.000143117205485,
    0.0001415219031888,0.0001392512237918,0.0001363477432527,0.0001328556875006,
    0.0001288206103493,0.0001242890771936,0.0001193083561163,0.0001139261179291,
    0.0001081901465563,0.0001021480610497,9.584705040331e-05,8.933362221366e-05,
    8.265336610148e-05, 7.58507326897e-05,6.896882880168e-05,6.204922942166e-05,
    5.513180683311e-05,4.825457723075e-05,4.145356498288e-05,3.476268460585e-05,
    2.821364040185e-05,2.183584360561e-05,1.565634678417e-05,9.699795139872e-06,
    3.988394276566e-06,-1.45810609247e-06,-6.622413093415e-06,-1.148967696459e-05,
    -1.604746338236e-05,-2.028571262468e-05,-2.419668640449e-05,-2.777490324557e-05,
    -3.101706330729e-05,-3.392196359045e-05,-3.649040447623e-05,-3.872508856221e-05,
    -4.063051276577e-05,-4.221285466426e-05,-4.347985403471e-05,-4.444069054344e-05,
    -4.510585851781e-05,-4.548703970894e-05,-4.55969749267e-05,-4.544933539516e-05,
    -4.505859464089e-05,-4.443990168575e-05,-4.360895627331e-05,-4.258188681097e-05,
    -4.137513166232e-05,-4.000532437334e-05,-3.848918336424e-05,-3.684340656561e-05,
    -3.508457142398e-05,-3.322904064735e-05,-3.129287400755e-05,-2.929174646215e-05,
    -2.724087280603e-05,-2.515493901019e-05,-2.304804035553e-05,-2.09336264194e-05,
    -1.882445292626e-05,-1.67325404284e-05,-1.46691397402e-05,-1.264470400862e-05,
    -1.066886726586e-05,-8.750429274352e-06,-6.897346443335e-06,-5.116728566267e-06,
    -3.414841103421e-06,-1.797112710393e-06,-2.68147693989e-07,1.168256939968e-06,
     2.50909019587e-06,3.752101914263e-06,4.895774081742e-06,5.939288997055e-06,
    6.882494667529e-06,7.725867809676e-06,8.470474824467e-06,9.117931112671e-06,
    9.670359087703e-06,1.013034523403e-05,1.050089654733e-05, 1.07853966795e-05,
    1.098756209662e-05,1.111139854181e-05,1.116115807743e-05, 1.11412969628e-05,
    1.105643460415e-05,1.091131379374e-05,1.071076243461e-05,1.045965692681e-05,
    1.016288736984e-05,9.825324715501e-06,9.451789984276e-06,9.047025638198e-06,
    8.615669182945e-06,8.162229052534e-06,7.691062811072e-06,7.206357687999e-06,
    6.712113445977e-06,6.212127564293e-06, 5.70998270529e-06,5.209036417136e-06,
    4.712413012994e-06,4.222997554721e-06,3.743431858291e-06,3.276112428547e-06,
    2.823190222353e-06,2.386572131977e-06,1.967924074433e-06,1.568675567601e-06,
    1.190025670121e-06,8.329501594459e-07,4.982098207634e-07,1.863597189845e-07,
    -1.022406736825e-07,-3.674166206794e-07,-6.091666585516e-07,-8.276506499086e-07,
    -1.023177469212e-06,-1.196192434337e-06,-1.347264591949e-06,-1.477073959194e-06,
    -1.586398818377e-06,-1.676103154897e-06,-1.747124322166e-06,-1.800461010331e-06,
     -1.8371615886e-06,-1.858312883801e-06,-1.865029450595e-06,-1.858443381571e-06,
    -1.839694698286e-06,-1.809922357297e-06,-1.770255898354e-06,-1.721807755253e-06,
    -1.66566624344e-06,-1.602889232294e-06,-1.534498504222e-06,-1.461474797188e-06,
    -1.384753522182e-06,-1.305221142414e-06,-1.223712196663e-06,-1.141006945285e-06,
    -1.057829613882e-06,-9.748472065307e-07, -8.9266885781e-07,-8.118456905982e-07,
    -7.328711447849e-07,-6.561817405742e-07,-5.821582390192e-07,-5.111271617299e-07,
    -4.43362631373e-07,-3.790884945852e-07,-3.184806892494e-07,-2.616698186936e-07,
    -2.087438962657e-07,-1.597512248612e-07,-1.147033773472e-07,-7.357824536324e-08,
    -3.63231257122e-08,-2.857815413658e-09,2.692231151672e-08,5.314327041678e-08,
    7.594949815426e-08, 9.55009716263e-08,1.119704308432e-07,1.255407226258e-07,
    1.364022787155e-07,1.447507399137e-07,1.507847357178e-07,1.547038268493e-07,
    1.567066160718e-07,1.569890307867e-07, 1.55742779097e-07,1.531539793319e-07,
     1.49401961455e-07, 1.44658237333e-07,1.390856355234e-07,1.328375950572e-07,
    1.260576116465e-07,1.188788288326e-07,1.114237658173e-07,1.038041730719e-07,
    9.612100630977e-08,8.846450901601e-08,8.091439346571e-08,7.354011000697e-08,
    6.640119434429e-08,5.954768261654e-08,5.302058421579e-08,4.685240253346e-08,
    4.106769413593e-08, 3.56836572588e-08,3.071074095525e-08,2.615326673332e-08,
    2.201005505932e-08,1.827504968272e-08,1.493793334217e-08,1.198472903689e-08,
    9.398381682355e-09,7.159315609669e-09,5.245964004573e-09,3.635267011282e-09,
      2.3031358399e-09,1.224880810778e-09,3.756018388686e-10,-2.694595974458e-10,
    -7.346074495739e-10,-1.043417026393e-09,-1.218499392545e-09,-1.281303376423e-09,
    -1.25195397101e-09
};
