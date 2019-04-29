#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
#define pb push_back

vector <pair<double,double> > data;
vector <int> vis;
vector <int> cl;
int current_cluster=1;
vector<vector<int> > clusters;

double eps = 10;
int MinPts = 4;


double distance(int,int);

int main(){

	int n,d;
	cin>>n>>d;
	data.resize(n);
	vis.resize(n,0);
	cl.resize(n,0);
	for(int i=0;i<n;i++){
		cin>>data[i].first;
		cin>>data[i].second;
	}

	for(int i=0;i<n;i++){
		if(vis[i]==1)
		{
			continue;
		}
		int p = i;
		vis[p]=1;
		vector <int> N;
		for(int j=0;j<n;j++){
			if(distance(p,j) <= eps){
				N.push_back(j);
			}
		}
		if(N.size()<MinPts)
			continue;

		vector<int> cluster;
		cluster.push_back(p);
		cl[p]=current_cluster;

		for(int j=0;j<N.size();j++){
			if(vis[N[j]]==0){
				vis[N[j]]=1;
				cluster.push_back(N[j]);
				cl[N[j]]=current_cluster;


				vector <int> Np;
				for(int k=0;k<n;k++){
					if(distance(k,N[j]) <= eps){
						Np.push_back(k);
					}
				}
				if(Np.size()>=MinPts){
					for(auto it:Np){
						N.push_back(it);
					}
				}


			}
			if(cl[N[j]]==0){
				cluster.push_back(N[j]);
				cl[N[j]]=current_cluster;
			}
		}
		clusters.push_back(cluster);
		current_cluster++;
	}

	for(auto it:clusters){
		if(it.size()==1)
			continue;
		cout<<it.size()<<endl;
		//for(auto it1:it){
		//	cout<<data[it1].first<<' '<<data[it1].second<<' ';
		//}
		//cout<<endl;
	}

	return 0;
}

double distance(int a,int b){
	double res = (data[a].fi-data[b].fi)*(data[a].fi-data[b].fi) +
		(data[a].se-data[b].se)*(data[a].se-data[b].se) ;
	res = sqrt(res); 
	return res;
}
