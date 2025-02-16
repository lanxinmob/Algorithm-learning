#include<stdio.h>
int n, m, a[105], ans;

void dfs(int idx, int sum) {
    // 如果索引超出范围或者当前和已经超过目标值m，则直接返回
    if (idx > n || sum > m) return;

    // 如果当前和等于目标值m，计数器加1并返回
    if (sum == m) {
        ans++;
        return;
    }

    // 选择第idx个数
    dfs(idx + 1, sum + a[idx]);

    // 不选择第idx个数
    dfs(idx + 1, sum);
}

int main() {
    scanf("%d %d",&n,&m); // 输入数组长度n和目标值m
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]); // 输入数组元素
    }

    dfs(0, 0); // 从第0个元素开始，当前和为0
    printf("%d",ans); // 输出满足条件的组合数量
    return 0;
}