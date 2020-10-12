
#!/usr/bin/python
 
import sys
 
# Print total number of arguments
#print ('Total number of arguments:', format(len(sys.argv)))
 
# Print all arguments
#print ('Argument List:', str(sys.argv))
 
# Print arguments one by one
#print ('First argument:',  str(sys.argv[0]))
#print ('Second argument:',  str(sys.argv[1]))
#print ('Third argument:',  str(sys.argv[2]))
#print ('Fourth argument:',  str(sys.argv[3]))

data0=sys.argv[1]
data1=sys.argv[2]
data2=sys.argv[3]
data3=sys.argv[4]
data4=sys.argv[5]


from sklearn.model_selection import train_test_split
import pandas as pn
import numpy as np 
from sklearn.neighbors import KNeighborsClassifier 
  
# loading the iris dataset 
#Reading Data and converting it to numpy array
data=pn.read_csv("./Data/dataset.csv")
data=np.asarray(data)

#Separating label - y(Cost in this case) and features - X
X=data[:,:data.shape[1]-1]
d=data[:,-1:]
y=d.ravel()

  
# X -> features, y -> label 

  
# dividing X, y into train and test data 
X_train, X_test, y_train, y_test = train_test_split(X, y, random_state = 20) 
  
# training a KNN classifier 

knn = KNeighborsClassifier(n_neighbors = 3).fit(X, y) 
# accuracy on X_test 
#accuracy = knn.score(X_test, y_test) 
#print (accuracy) 
  
 
knn_predictions = knn.predict([[data0],[data1],[data2],[data3],[data4]])  

from collections import Counter
severity= [word for word, word_count in Counter(knn_predictions).most_common(1)]    
        
s="%s%s%s%s%s%s"%(knn_predictions[0],knn_predictions[1],knn_predictions[2],knn_predictions[3],knn_predictions[4],severity[0])        
print(s)
