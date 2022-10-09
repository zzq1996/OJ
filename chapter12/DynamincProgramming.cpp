/**
* @Author : zhang
* @create 2022/3/8 15:00
*/


#include <cstring>
#include "DynamincProgramming.h"
#include "iostream"

using namespace std;

/*
 * @Description 计算n阶上楼方式（非递归）——（一次可走一阶或两阶）
 * 斐波那契数的变体，可得递推关系：dp[n]=dp[n-1]+dp[n-2]
 * 其中dp[0]=0，dp[1]=1
 *
 */


void DynamincProgramming::L12_1() {

    long long dp[91];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;

    //利用数组，记录结果
    for (int i = 3; i < 91; ++i) {
        dp[i]=dp[i-1]+dp[i-2];
    }

    int n=0;

    while (cin>>n){
        cout<<dp[n]<<endl;
    }

}


/*
 * @Description 求最大子序列和
 *
 * 法一：DP
     * 设置dp[i]是以A[i]作为末尾的连续序列的最大和
     * 得到状态转移方程dp[i]=max{ A[i], dp[i-1]+A[i] }
     * 只需将i从小到大枚举并依次遍历，即可得到整个dp数组，该数组的最大值即为最大连续子序列和
     *
   TODO
   法二：分治
     * 最大子序列可能出现的位置：左、右、中间
     * 算导40页
     *
 */
long long L_arr[1000000];
long long L_dp[1000000];

/*
 * @Description 返回最大子序列的值
 */
long long maxSubsequence(int n){

    long long maximum=0;

    for (int i = 0; i < n; ++i) {

        if (i==0){
            L_dp[i]=L_arr[i];

        }else{
            L_dp[i]=max(L_arr[i],L_dp[i-1]+L_arr[i]);
        }

        maximum=max(maximum,L_dp[i]);
    }
    return maximum;
}

void DynamincProgramming::L12_2() {
    int n;
    while (cin>>n){
        for (int i = 0; i < n; ++i) {
            //先对L_arr赋值，再调用函数
            cin>>L_arr[i];
        }

        long long answer= maxSubsequence(n);
        cout<<answer;
    }
}


/*
 * @Description 输出最大子矩阵
 * 矩阵的和：矩阵中所有元素相加
 *
 * 假设原矩阵中最大子矩阵所在的行是从i到j，那么：
 *  1、i=j，原问题转化为求第i行元素的最大连续子序列和
 *  2、i!=j，把从第i行到第j行的所有行的元素加起来，得到只有一行的一维数组，这个一维数组的最大连续子序列的和便是最大子矩阵
 */

int L_matrix1[100][100];//原始矩阵

int L_total[100][100];//辅助矩阵




/*
 * @Description 获得最大子矩阵
 */
int maxSubMatrix(int n){

    int maximal=0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {//获得一维数组

                if (i==0){
                    L_arr[k]=L_total[i-1][k];
                }else{
                    L_arr[k]=L_total[j][k]-L_total[i-1][k];
                }

            }

            int current= maxSubsequence(n);

            maximal= max(maximal,current);
        }
    }
    return maximal;
}


/*
 * @Description 主程序
 */
void DynamincProgramming::L12_3() {
    int n;
    while (cin>>n){

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>L_matrix1[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {//初始化辅助函数
            for (int j = 0; j < n; ++j) {
                if (i==0){
                    L_total[i][j]=L_matrix1[i][j];
                }else{
                    L_total[i][j]=L_total[i-1][j]+L_matrix1[i][j];
                }
            }
        }

        int answer= maxSubMatrix(n);
        cout<<answer<<endl;
    }

}



/*
 * @Description 最长递增子序列
 * 输出：求给定序列的所有递增子序列中（不必连续）最长的那个子序列长度
 *
 * 设置数组dp，令dp[i]表示以A[i]作为末尾的最长递增子序列的长度，两种情况：
 *  1、A[i]之前的元素都比A[i]大，最长递增子序列只有A[i]本身，即dp[i]=1
 *  2、A[i]之前的元素A[j]比A[i]小，此时将A[i]添加到A[j]作为末尾的最长递增子序列，便构成一个新的递增子序列
 *
 *  dp[i]=max{ 1 , dp[j]+1  |  j<1 && A[j]<A[i]}
 */







/*
 * @Description 拦截的导弹数量
 *      ——求导弹的最长不增子序列
 *      状态转移方程：dp[i]=max{ 1,dp[j]+1 | j<1 && A[j] >= A[i] }
 */


void DynamincProgramming::L12_4() {
    int height[25];//导弹高度
    int dp[25];
    int n=0;
    while (cin>>n){

        for (int i = 0; i < n; ++i) {
            cin>>height[i];
        }

        int answer=0;

        for (int i = 0; i < n; ++i) {
            dp[i]=1;//初始化为1

            for (int j = 0; j < i; ++j) {

                if (height[i]<=height[j]){
                    dp[i]= max(dp[i],dp[j]+1);
                }

            }
            answer= max(answer,dp[i]);//dp数组的最大值
        }

        cout<<answer<<endl;
    }
}


/*
 * @Description 求最大上升子序列的和
 *
 * 将dp[i]作为以A[i]作为末尾的最大上升子序列的和
 *
 * dp[i]=max{ A[i] , dp[j]+A[i] | j<i && A[j]>A[i] }
 */


void DynamincProgramming::L12_5() {

    int arr[1000];
    int dp[1000];

    int n;
    while (cin>>n){
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }

        int answer=0;

        for (int i = 0; i < n; ++i) {
            dp[i]=arr[i];
            for (int j = 0; j < i; ++j) {

                if (arr[j]<arr[i]){
                    dp[i]=max(dp[i],dp[j]+arr[i]);
                }

            }
            answer= max(answer,dp[i]);
        }

        cout<<answer<<endl;
    }

}



/*
 * @Description LCS
 * 设置一个二维数组dp[][]，令dp[i][j]表示以S1[i]作为末尾和以S2[j]作为末尾的LCS（最长公共子序列）的长度，根据S1[i]和S2[j]的关系可分为：
 *  1、S1[i]=S2[j]，即S1中的第i个字符和S2中的第j个字符相同，
 *      此时必定存在一个LCS以S1[i]和S2[j]结尾，
 *      其他部分等价于S1中前i-1个字符和S2中前j-1个字符的LCS，
 *      于是这个字串的长度比dp[i-1][j-1]多1，
 *      即dp[i][j]=dp[i-1][j-1]+1
 *
 *  2、S1[i]!=S2[j]，此时LCS长度为S1中前i-1个字符和S2中前j个字符的LCS与S1中前i个字符和S2中前j-1个字符的LCS的较大者，
 *      即在两种情况下得到的LCS都不会因为其中一个字符串又增加了一个字符长度而改变，
 *      也就是dp[i][j]=max{ dp[i-1][y] , dp[i][j-1] }
 *
 * 从这两种情况得到状态转移方程：
 *      S1[i]=S2[j]     dp[i][j]=dp[i-1][j-1]+1
 *      S1[i]!=S2[j]    dp[i][j]=max{ dp[i-1][y] , dp[i][j-1] }
 *
 * 对于边界情况，若两个字符串中的其中一个为空串，则LCS为0，可得
 *      dp[i][0]=0（0<=i<=n）
 *      dp[0][j]=0（0<=j<=m）
 *
 * 由这样的状态转移，只需依次遍历i和j便可求得dp[i][j]的值，其时间复杂度为O(mn)
 *
 * 最终dp[n][m]中保存的值即为LCS长度
 */
void DynamincProgramming::L12_6() {

    char s1[1001];
    char s2[1001];
    int dp[1001][1001];

    while (cin>>(s1+1)>>(s2+1)){//从下标1开始输入
        int n= strlen(s1+1);
        int m= strlen(s2+1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {

                if (i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }

                if (s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                }

            }
        }

        cout<<dp[n][m]<<endl;

    }

}


/*
 * @Description 点菜问题
 */
void DynamincProgramming::L12_7() {

    int MAX=100;
    int dp[MAX];
    int v[MAX];//物品价值
    int w[MAX];//物品重量

    int n=0,m=0;//n件物品，m容量的背包

    while (cin>>n>>m){


        for (int i = 0; i < n; ++i) {
//            scanf("%d%d",&w[i],&v[i]);
            cin>>w[i]>>v[i];
        }

        memset(dp,0,sizeof(dp));
//        for (int i = 0; i <= m; ++i) {
//            dp[i]=0;
//        }

        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= w[i]; --j) {
                dp[j]= max(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        cout<<dp[m]<<endl;

    }
}

/*
 * @Description Piggy-Bank
 */
void DynamincProgramming::L12_8() {




}

/*
 * @Description TODO
 */
void DynamincProgramming::L12_9() {

}

/*
 * @Description TODO
 */
void DynamincProgramming::L12_10() {

}

/*
 * @Description TODO
 */
void DynamincProgramming::L12_11() {

}





