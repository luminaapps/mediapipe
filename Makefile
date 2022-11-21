framework:
	bazel build --config=ios_arm64 --cxxopt='-std=c++17' mediapipe/develop:PoseTrackingGpu
