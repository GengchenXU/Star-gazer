#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
    float degree[50];
    int num[50];
    int m,e=0;
    float max;
    cin >> m >> max;
    //int q = 0;
    //while (q <m ) {
    //    cin >> num[i] >> degree[i];
    //    q++;
    //    m--;//������������������m��������(ԭ������while(m>0))
    //}
    for (int i = 0; i < m; i++) {
        cin >> num[i] >> degree[i];
    }
    /*r[i]>=max&&degree[i] >= max &&
    ** �����ȶ����س̶Ƚ��дӴ�С����
    */
    //bool flag = false;
    for (int i = 0; i < m; i++) {
        //if (degree[i] >= max) {
        //    flag = true;
        //}
        for (int j = 0; j < m; j++) {
            float tempdegree;
            int tempnum;
            if ( degree[i]>=max&&degree[i] > degree[j]) {
                tempdegree = degree[i];
                tempnum = num[i];
                degree[i] = degree[j];
                num[i] = num[j];
                degree[j] = tempdegree;
                num[j] = tempnum;
            }
        }
    }
    for(int i=0;i<m;i++){
    	if(degree[i]>max){
      printf("%03d ", num[i]);
    	cout<<(fixed) << setprecision(1) <<degree[i]<<endl;}}
    	 if(degree[0]<max) cout<<"None.";	
	 
	return 0;
}
	
	
	/*
    **�������������жϷ�������һ����еĻ������������Ҫ������Ӧ�ĸı�
    */
  // bool flag = false;
   /* for (int i = 0; i < m; i++) {
    if (degree[i] >= max) {
            flag = true;
        }
    }
    //cout << flag << endl;
    if (flag == false) {
        //cout << "None" << endl;//֪��Ϊʲôһֱ������
        cout << "None." << endl;
        return 0;//ֱ�ӽ���
    }
    
    else {
        for (int i = 0; i < m; i++) {
            if (degree[i] >= max) {
                printf("%03d", num[i]);
                //std::cout << std::setprecision(1) << degree[i] << '\n';
                //cout << ' ' << fixed << setprecision(1) << degree[i] << endl;
                cout << ' ' << setiosflags(ios::fixed) << setprecision(1) << degree[i] << endl;
            }
        }
        return 0;
    }
    
    
 
}*/




 
