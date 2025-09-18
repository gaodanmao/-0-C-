class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> res(n,vector<int>(n,0));
        //使用vector来定义一个二维数组，那么前面的n就是正整数n，代表n个数组中有n个元素，默认值为0
        int startx = 0,starty = 0;
        //定义每循环一个圈的起始位置
        int loop = n/2;
        //每个圈循环几次，例如n为奇数3，那么loop = 1只是循环一圈，矩阵中间的值需要单独处理
        int mid = n/2;
        //矩阵中间的位置，例如：n为3，中间的位置就是（1，1）；n为5，中间的值就是（2，2）
        int count = 1;
        //用来给矩阵中每一个空格赋值
        int offset = 1;
        //需要控制每一条边遍历的长度，每次循环有边界先收缩一位,那么需要我们offset增加一位，再减去
        int i,j;
        while(loop --){
            //那么我们n为3的话，loop起初就是1，那么就会循环一次，如果n为5，loop就是2，那么就会循环两次嘛！
            i = startx;
            j = starty;
            //例如1的位置应该就是（i,j)==(0,0)这样子喽
            
            //那么我们开始旋转的过程（当然我们二分法需要左闭右开）
            //1.上面一条边的旋转
            for(i;i<n-offset;i++){
                res[j][i]=count++;//事实上数值的变化仅仅靠简单的++就可以胜任了
            }
            //2.右边一条边的旋转
            for(j;j<n-offset;j++){
                res[j][i]=count++;//本来想换掉j和i的，但是我发现其实输出的顺序是一排一排的
            }
            //3.下面一条边的旋转
            for(;i>startx;i--){
                res[j][i]=count++;//count直接++就可以了
            }
            //4.左边一条边的旋转
            for(;j>starty;j--){
                res[j][i]=count++;
            }

            //那么我们第一圈就这样结束了，那么我们开始第二圈，注意第一圈起始位置是（0，0），第二圈起始位置是（1，1）
            startx++;
            starty++;

            //offset控制每一圈里每一边的遍历的长度
            offset++;
        }
        //如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if( n%2 ){
            res[mid][mid]=count;//因为count是赋值后再+1的
        }
        return res;
    }
};
