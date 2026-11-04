"""Lab 8: SVM kernels, scratch decision tree, and KNN."""
from pathlib import Path
import numpy as np, pandas as pd, matplotlib.pyplot as plt
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import make_pipeline
from sklearn.svm import SVC
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import *
ROOT=Path(__file__).resolve().parents[1]; OUT=ROOT/'outputs'; OUT.mkdir(exist_ok=True)
class Tree:
 def __init__(self,criterion='entropy',depth=0,max_depth=4): self.c=criterion; self.d=depth; self.md=max_depth
 def imp(self,y):
  p=np.bincount(y,minlength=2)/len(y); return (-(p[p>0]*np.log2(p[p>0])).sum() if self.c=='entropy' else 1-(p*p).sum())
 def fit(self,X,y):
  self.pred=int(np.bincount(y).argmax())
  if self.d>=self.md or len(np.unique(y))==1:return self
  best=(-1,None,None)
  for j in range(X.shape[1]):
   for t in np.unique(X[:,j])[:-1]:
    l=X[:,j]<=t; r=~l
    if l.any() and r.any():
     gain=self.imp(y)-(l.sum()*self.imp(y[l])+r.sum()*self.imp(y[r]))/len(y)
     if gain>best[0]:best=(gain,j,t)
  if best[1] is None:return self
  self.j,self.t=best[1:]; self.left=Tree(self.c,self.d+1,self.md).fit(X[X[:,self.j]<=self.t],y[X[:,self.j]<=self.t]); self.right=Tree(self.c,self.d+1,self.md).fit(X[X[:,self.j]>self.t],y[X[:,self.j]>self.t]); return self
 def predict(self,X): return np.array([self.pred if not hasattr(self,'j') else (self.left.predict(x[None])[0] if x[self.j]<=self.t else self.right.predict(x[None])[0]) for x in X])
def main():
 d=load_wine(); X=d.data; y=(d.target==0).astype(int); a,b,c,e=train_test_split(X,y,test_size=.3,stratify=y,random_state=42); rows=[]
 for k in ['linear','poly','rbf','sigmoid']:
  m=make_pipeline(StandardScaler(),SVC(kernel=k)).fit(a,c); p=m.predict(b); rows.append([k,accuracy_score(e,p),precision_score(e,p),recall_score(e,p),f1_score(e,p)]); pd.DataFrame(confusion_matrix(e,p)).to_csv(OUT/f'svm_{k}_confusion.csv',index=False)
 pd.DataFrame(rows,columns=['kernel','accuracy','precision','recall','f1']).to_csv(OUT/'svm_comparison.csv',index=False)
 for crit in ['entropy','gini']:
  p=Tree(crit).fit(a,c).predict(b); pd.DataFrame([[crit,accuracy_score(e,p)]],columns=['criterion','accuracy']).to_csv(OUT/f'tree_{crit}.csv',index=False)
 kn=[]
 for k in range(1,16,2): kn.append([k,make_pipeline(StandardScaler(),KNeighborsClassifier(k)).fit(a,c).score(b,e)])
 pd.DataFrame(kn,columns=['k','accuracy']).to_csv(OUT/'knn_accuracy.csv',index=False); plt.plot(*zip(*kn),marker='o'); plt.xlabel('K'); plt.ylabel('accuracy'); plt.tight_layout(); plt.savefig(OUT/'knn_accuracy.png',dpi=140); plt.close()
if __name__=='__main__':main()
