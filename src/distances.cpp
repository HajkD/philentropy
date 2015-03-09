#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

//' @export
// [[Rcpp::export]]
double euclidean(NumericVector P, NumericVector Q){
        
        int P_len = P.size();
        int Q_len = Q.size();
        
        if(P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        double dist = 0;
        double diff = 0;
        
        for(int i = 0; i < P_len; i++){
                
                diff = P[i] - Q[i];
                dist = dist + (diff * diff);
                        
        }
        
        return sqrt(dist);
}


//' @export
// [[Rcpp::export]]
double cityblock(NumericVector P, NumericVector Q){
        
        int P_len = P.size();
        int Q_len = Q.size();
        
        if(P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        double dist = 0;
        double diff = 0;
        
        for(int i = 0; i < P_len; i++){
                
                diff = abs(P[i] - Q[i]);
                dist = dist + diff;
                        
        }
        
        return dist;
}



//' @export
// [[Rcpp::export]]
double minkowski(NumericVector P, NumericVector Q, double n){
        
        int P_len = P.size();
        int Q_len = Q.size();
        
        if(P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        double dist = 0.0;
        double diff = 0.0;
        
        for(int i = 0; i < P_len; i++){
                
                diff = pow(abs(P[i] - Q[i]), n);
                dist = dist + diff;
                        
        }
        
        return pow(dist ,  1.0/n);
}


//' @export
// [[Rcpp::export]]
double chebyshev(NumericVector P, NumericVector Q){
        
        int P_len = P.size();
        int Q_len = Q.size();
        
        if(P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        double dist = 0;
        double diff = 0;
        
        for(int i = 0; i < P_len; i++){
                
                diff = abs(P[i] - Q[i]);
                
                if(diff > dist)
                     dist = diff;
                        
        }
        
        return dist;
}


//' @export
// [[Rcpp::export]]
double sorensen(NumericVector P, NumericVector Q){
        
        int P_len = P.size();
        int Q_len = Q.size();
        
        if(P_len != Q_len){
                Rcpp::stop("The vectors you are comparing do not have the same length!");
        }
        
        double dist1 = 0;
        double dist2 = 0;
        double diff = 0;
        double sum = 0;
        
        for(int i = 0; i < P_len; i++){
                
                diff = abs(P[i] - Q[i]);
                sum = P[i] + Q[i];
                
                dist1 = dist1 + diff;
                dist2 = dist2 + sum;
                
        }
        
        
        return dist1/dist2;
}





