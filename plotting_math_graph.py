import array as arr
import re
from matplotlib import pyplot as plt
from matplotlib import style

#creating an array with 'd' as double float
time = arr.array('d',[]); #array for time
value = arr.array('d',[]); #array for voltage/current

user_input = input();


#reading file

filename = "rangkaian_RC.csv";
file = open(filename,'r');

#reading entire line in file eksternal
with open(filename,'r') as filehandle:
    for line in filehandle:
        #cek = re.split(" |\n",line); #splitting the line with the deliminator " " or "\n"
        token = re.split(";",line); #splitting the line with the deliminator ";"
        time.append(float(token[0]));
        value.append(float(token[1]));

#displaying the graphic
style.use('ggplot')
plt.scatter(time, value)#, align='center')
if((user_input == 'v') or (user_input == 'V')) :
    plt.title('Voltage vs Time');
    plt.ylabel('Voltage(V)');
    plt.xlabel('Time(s)');
elif ((user_input == 'i') or (user_input == 'I')) :
    plt.title('Current vs Time');
    plt.ylabel('Current(A)');
    plt.xlabel('Time(s)');
else :
    print("Inputan user salah.\n");
plt.show()        

