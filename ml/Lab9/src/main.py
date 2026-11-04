"""Lab 9: multiclass metrics, digits KNN/SVM, and chronological stock-style classification."""
from pathlib import Path
import numpy as np, pandas as pd
from sklearn.datasets import load_digits
from sklearn.model_selection import train_test_split
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.metrics import *
ROOT=Path(__file__).resolve().parents[1]; OUT=ROOT/'outputs'; OUT.mkdir(exist_ok=True)
def ovr(cm):
 n=cm.sum(); rows=[]
 for i in range(len(cm)):
  tp=cm[i,i]; fn=cm[i,:].sum()-tp; fp=cm[:,i].sum()-tp; tn=n-tp-fn-fp; rows.append([i,tp,tn,fp,fn,tp/(tp+fn),tp/(tp+fp),tn/(tn+fp),2*tp/(2*tp+fp+fn)])
 return pd.DataFrame(rows,columns=['class','TP','TN','FP','FN','recall','precision','specificity','f1'])
def main():
 cm=np.array([[40,2,1,0,0],[3,35,2,0,0],[0,1,42,2,0],[0,0,3,37,2],[0,0,0,2,38]]); pd.DataFrame(cm).to_csv(OUT/'confusion_matrix_5x5.csv',index=False); ovr(cm).to_csv(OUT/'confusion_matrix_5x5_ovr.csv',index=False)
 d=load_digits(); X=d.data/16.; y=d.target; Xtr,Xte,ytr,yte=train_test_split(X,y,test_size=.25,stratify=y,random_state=42); rows=[]
 for name,m in [('KNN',make_pipeline(StandardScaler(),KNeighborsClassifier(3))),('SVM',make_pipeline(StandardScaler(),SVC()))]:
  m.fit(Xtr,ytr); p=m.predict(Xte); rows.append([name,accuracy_score(yte,p),precision_score(yte,p,average='weighted'),recall_score(yte,p,average='weighted'),f1_score(yte,p,average='weighted')]); pd.DataFrame(confusion_matrix(yte,p)).to_csv(OUT/f'digits_{name.lower()}_confusion.csv',index=False)
 pd.DataFrame(rows,columns=['model','accuracy','precision_weighted','recall_weighted','f1_weighted']).to_csv(OUT/'digits_comparison.csv',index=False)
 rng=np.random.default_rng(42); close=100+np.cumsum(rng.normal(.05,1,700)); vol=rng.integers(1000,5000,700); ret=np.r_[0,np.diff(close)/close[:-1]]; ma=pd.Series(close).rolling(10).mean().bfill().to_numpy(); X=np.c_[close,vol,ret,ma]; y=(np.r_[close[1:],close[-1]]>close).astype(int); a,b,c,e=X[:500],X[500:],y[:500],y[500:]; rows=[]
 for name,m in [('KNN',make_pipeline(StandardScaler(),KNeighborsClassifier(5))),('SVM',make_pipeline(StandardScaler(),SVC()))]:
  m.fit(a,c); p=m.predict(b); rows.append([name,accuracy_score(e,p),precision_score(e,p),recall_score(e,p),f1_score(e,p)]); pd.DataFrame(confusion_matrix(e,p)).to_csv(OUT/f'stock_{name.lower()}_confusion.csv',index=False)
 pd.DataFrame(rows,columns=['model','accuracy','precision','recall','f1']).to_csv(OUT/'stock_comparison.csv',index=False)
if __name__=='__main__':main()
