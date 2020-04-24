#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int lo,up,mi;
int ap(int pl[],int x,int mid,int d){
    for(int i=0;i<x;i++){
        if((mid-pl[i])<d){
        mi=mid-pl[i];
        lo=mid;
        up=pl[i];
        }
    }
return mi;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kth_largest(int arr[],int l,int r,int k){

        int pos = partition(arr, l, r);


        if (pos-l == k)
            return arr[pos];
        if (pos-l > k-1)
            return kth_largest(arr, l, pos-1, k);
        return kth_largest(arr, pos+1, r, k-pos+l-1);

}


int cp(int p[],int m){
   if(m<=3){
        int i=0,d;
        for (i;i<m;i++){
            for(int j=i+1;j<m;j++){
                 d=p[i]-p[j];
                if(d<0) d=0-d;
                if(mi>d){
                  mi=d;
                  lo=p[i];
                  up=p[j];
               }
        }
        }
        return mi;
   }
   else{
    int x_mid=kth_largest(p,0,m-1,m/2);

    int pl[m],pr[m],k=0,l=0,lm,rm;
    for(int i=0;i<m;i++){
            if(p[i]<x_mid){
                pl[k]=p[i];
                k=k+1;
            }
            else if(p[i]>=x_mid){
                pr[l]=p[i];
                l=l+1;
            }
    }
    lm=k;
    rm=l;
    int dl=cp(pl,lm);
    int dr=cp(pr,rm);
    int q,dlr;
    if(dl<dr) {
            q=dl;
    }
    else {
            q=dr;
    }
    dlr=ap(pl,lm,x_mid,q);
    if(dlr<q){q=dlr;
    }
    return q;
    }
}
int main(){
    int a;
    char c[20];
    cout<<"enter the name of the text file consisting of 1-D points"<<endl;
    cin>>c;
ifstream infile;
infile.open(c);
int p[100],i=0;
while(infile!=NULL){
    infile>>a;
    p[i]=a;
    i=i+1;
}
int m=i-1;
mi=p[0]-p[1];
if(mi<0) mi=0-mi;
lo=p[0];
up=p[1];
cout<<"the closest distance is"<<endl;
cout<<cp(p,m)<<endl;;
cout<<"the closest pair of points are"<<endl;
cout<<"("<<lo<<","<<up<<")"<<endl;
return 0;
}