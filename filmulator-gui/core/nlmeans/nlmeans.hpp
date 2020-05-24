#ifndef NLMEANS_H
#define NLMEANS_H

#include <vector>
#include <array>
#include <Eigen/Dense>

struct clusterInfo{
    std::vector<float> center;
    std::vector<int> members;
    double summedSquareDistances;
};

std::vector<float> bisecting_kmeans(float* const X, const int numPoints, const int numDimensions, const int k, const std::optional<float> threshold = std::nullopt);

template <class MatT>
Eigen::Matrix<typename MatT::Scalar, MatT::ColsAtCompileTime, MatT::RowsAtCompileTime>
pseudoinverse(const MatT& mat, typename MatT::Scalar tolerance = typename MatT::Scalar{ 1e-4 });

std::vector<float> calcC1ChanT(std::vector<float> centers, int numClusters, const float h);

void calcW(float* const Aguide_ptr, float* const centers_ptr,
           ptrdiff_t rangeDims, ptrdiff_t numClusters, float const h,
           float* W_ptr);

void expandDims(float* const I, int radius, int sizeX, int sizeY, float* output);

void highDimBoxFilter(float* const A, float* const W, float* const C1chanT, ptrdiff_t const numClusters, float* output);

void kMeansNLMApprox(float* const I, const int maxClusters, const float clusterThreshold, const float h, const int sizeX, const int sizeY, float* output);

std::tuple<std::vector<float>,std::vector<bool>,std::array<double,2>,std::array<int,2>> splitCluster(float* const X, const int numPoints, const int numDimensions);

#endif // NLMEANS_H
