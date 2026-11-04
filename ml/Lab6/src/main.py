"""Lab 6: scratch K-Means and hierarchical clustering."""
from pathlib import Path
import numpy as np, pandas as pd, matplotlib.pyplot as plt
from sklearn.datasets import make_blobs
from sklearn.preprocessing import StandardScaler
from scipy.cluster.hierarchy import dendrogram, linkage
ROOT=Path(__file__).resolve().parents[1]; OUT=ROOT/'outputs'; OUT.mkdir(exist_ok=True)
class KMeansScratch:
 def __init__(self,k=3,max_iter=100,tol=1e-4,seed=42): self.k=k; self.max_iter=max_iter; self.tol=tol; self.rng=np.random.default_rng(seed)
 def fit(self,X):
  X=np.asarray(X,float); self.centroids=X[self.rng.choice(len(X),self.k,replace=False)].copy(); self.history=[]
  for it in range(self.max_iter):
   labels=((X[:,None,:]-self.centroids[None,:,:])**2).sum(2).argmin(1); new=np.array([X[labels==j].mean(0) if np.any(labels==j) else self.centroids[j] for j in range(self.k)]); self.history.append(float(np.linalg.norm(new-self.centroids))); self.centroids=new
   if self.history[-1]<self.tol: break
  self.labels_=labels; self.n_iter_=it+1; return self
def save(X,m,name):
 plt.figure(figsize=(6,4)); plt.scatter(X[:,0],X[:,1],c=m.labels_,cmap='tab10',s=18); plt.scatter(m.centroids[:,0],m.centroids[:,1],c='black',marker='X',s=120); plt.title(name); plt.xlabel('feature 1'); plt.ylabel('feature 2'); plt.tight_layout(); plt.savefig(OUT/f'{name.lower().replace(" ","_")}.png',dpi=140); plt.close()
def agglomerative(X,link,k):
 groups=[{i} for i in range(len(X))]
 def dist(a,b):
  d=np.array([np.linalg.norm(X[i]-X[j]) for i in a for j in b]); return {'single':d.min(),'complete':d.max(),'average':d.mean()}[link]
 while len(groups)>k:
  i,j=min(((i,j) for i in range(len(groups)) for j in range(i+1,len(groups))),key=lambda z:dist(groups[z[0]],groups[z[1]])); groups[i]|=groups.pop(j)
 labels=np.zeros(len(X),int)
 for c,g in enumerate(groups): labels[list(g)]=c
 return labels
def main():
 X,_=make_blobs(n_samples=180,centers=[(-3,-2),(0,3),(3,-1)],cluster_std=.8,random_state=42); Xo=np.vstack([X,[[8,8],[-8,-7],[9,-6]]]); iris=pd.read_csv(ROOT.parent/'lab4/irisPrediction1/Iris.csv').iloc[:,[3,4]].to_numpy(); sets=[('clean_blobs',X),('with_outliers',Xo),('iris_features',iris)]
 for n,z in sets: save(z,KMeansScratch().fit(z),f'kmeans_{n}')
 z=StandardScaler().fit_transform(iris)
 for link in ['single','complete','average']:
  lab=agglomerative(z,link,3); plt.figure(figsize=(5,4)); plt.scatter(z[:,0],z[:,1],c=lab,cmap='tab10',s=15); plt.title(f'Agglomerative ({link})'); plt.tight_layout(); plt.savefig(OUT/f'agglomerative_{link}.png',dpi=140); plt.close()
 plt.figure(figsize=(7,4)); dendrogram(linkage(z,method='average'),truncate_mode='lastp',p=20); plt.title('Dendrogram'); plt.tight_layout(); plt.savefig(OUT/'dendrogram.png',dpi=140); plt.close(); pd.DataFrame({'experiment':[n for n,_ in sets]}).to_csv(OUT/'results.csv',index=False)
if __name__=='__main__': main()
