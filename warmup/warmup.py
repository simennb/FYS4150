from pylab import *

filename = 'output.txt'
infile = open(filename,'r')

h = []
two_float = []
two_double = []
three_float = []
three_double = []

i = 0
for line in infile:
    data = line.split(' ')
    if i>0:
        h.append(float(data[0]))
        two_float.append(float(data[1]))
        two_double.append(float(data[2]))
        three_float.append(float(data[3]))
        three_double.append(float(data[4]))

    i += 1

h = array(h)
two_float = array(two_float)
two_double = array(two_double)
three_float = array(three_float)
three_double = array(three_double)

log10h = log10(h)
f_exact = 1/3.
eps_2s = log10(abs((two_float-f_exact)/f_exact))
eps_2d = log10(abs((two_double-f_exact)/f_exact))

eps_3s = log10(abs((three_float-f_exact)/f_exact))
eps_3d = log10(abs((three_double-f_exact)/f_exact))

# Plotting
from matplotlib import rc
rc('font',**{'family':'serif'})

fsize = 16
figure()
grid('on')
plot(log10h,eps_2s,log10h,eps_2d,log10h,eps_3s,log10h,eps_3d)
legend([r"$f'_{2,single}$",r"$f'_{2,double}$",r"$f'_{3,single}$",r"$f'_{3,double}$"],fontsize=fsize)
xlabel(r'$\log10(h)$',fontsize=fsize)
ylabel(r"$\varepsilon$",fontsize=fsize)
title('Error of two/three point equations in single/double precision')
savefig('warmup.png')
show()
