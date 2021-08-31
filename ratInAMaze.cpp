#include<iostream>
using namespace std;

bool check(int** arr, int** visited, int n, int x, int y){
    if(x == n-1 && y == n-1){
        return true;
    }

    if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] == 0 || visited[x][y] == 1){
        return false;
    }

    visited[x][y] = 1;

    if(check(arr, visited, n, x - 1, y)){
        return true;
    }

    if(check(arr, visited, n, x + 1, y)){
        return true;
    }

    if(check(arr, visited, n, x, y - 1)){
        return true;
    }

    if(check(arr, visited, n, x, y + 1)){
        return true;
    }

    visited[x][y] = 0;
    return false;
}

bool hasPath(int** arr, int n){
    int** visited = new int*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new int[n];
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }

    return check(arr, visited, n, 0, 0);
}

int main(){

    int** arr;
    int n;
    cout<<"ENTER THE SIZE OF THE MATRIX:";
    cin>>n;

    arr = new int*[n];

    cout<<"ENTER THE PATH OF THE MATRIX:\n";
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    if(hasPath(arr, n)){
        cout<<"THE RAT CAN REACH THE END OF THE MAZE!!!";
    }

    else{
        cout<<"THERE IS NO PATH FOR THE RAT TO CROSS THE MAZE!!!";
    }


    return 0;
}