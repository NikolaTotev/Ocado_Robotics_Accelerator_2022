//System headers
#include <cstdint>
#include <rclcpp/rclcpp.hpp>
#include <URFinalBridge.h>

static void runApp(
    const std::shared_ptr<URFinalBridge> &node) {
  node->run();
}

int32_t main(int32_t argc, char *argv[]) {
  rclcpp::InitOptions initOptions;
  initOptions.shutdown_on_sigint = false;
  rclcpp::init(argc, argv);

  auto node = std::make_shared<URFinalBridge>();
  const int32_t errCode = node->init();
  if (EXIT_SUCCESS != errCode) {
    std::cerr << "URFinalBridge::init() failed" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Starting UR Script Service" << std::endl;
  
    std::thread spinThread([&node]() {
    rclcpp::spin(node);
    });
  
  
  runApp(node);

  rclcpp::shutdown();
  spinThread.join();

  return EXIT_SUCCESS;
}