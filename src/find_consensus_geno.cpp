// find consensus genotype for each row of a genotype matrix

#include "find_consensus_geno.h"
#include <Rcpp.h>
using namespace Rcpp;

// find consensus genotype for each vector of calls
//
// NO missing values; use "NA" instead
//
// if all NA: return NA
// if no genotype most common: return NA
// otherwise return the most common genotype
//
std::string find_consensus_geno_1mar(const std::vector<std::string>& g)
{
    int n = g.size();

    // create hash
    std::map<std::string,int>counts;

    // count unique values that are not "NA"
    int n_notmissing = 0;
    for(int i=0; i<n; i++) {
        if(g[i] != "NA") {
            ++counts[g[i]];
            n_notmissing++;
        }
    }
    if(n_notmissing==0) return("NA");

    // find maximum; keep track of whether it's a tie
    int max_count = 0;
    std::string return_val = "NA";
    bool tie = true;
    for(std::map<std::string, int>::iterator p=counts.begin(); p != counts.end(); ++p) {
        if(p->second == max_count) {
            tie = true;
        }
        else if(p->second > max_count) {
            tie = false;
            max_count = p->second;
            return_val = p->first;
        }
    }

    // return "NA" if tie; otherwise return the consensus value
    if(tie) return("NA");
    return return_val;
}


// For each row (corresonding to a marker) in a genotype matrix,
//    apply the function above to find the "consensus" genotype
//
// [[Rcpp::export(".find_consensus_geno")]]
StringVector find_consensus_geno(StringMatrix g)
{
    int n_mar = g.rows();
    int n_ind = g.cols();
    StringVector result(n_mar);


    // loop over markers and apply consensus_geno (above)
    // oog...rough conversions StringVector <-> std::vector<std::string>
    for(int mar=0; mar<n_mar; mar++) {
        std::vector<std::string> input(n_ind);
        for(int ind=0; ind<n_ind; ind++)
            input[ind] = Rcpp::as<std::string>(g(mar,ind));

        result[mar] = find_consensus_geno_1mar(input);
    }

    return result;
}
