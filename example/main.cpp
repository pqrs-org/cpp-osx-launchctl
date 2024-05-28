#include <pqrs/osx/launchctl.hpp>

int main(void) {
  auto time_source = std::make_shared<pqrs::dispatcher::hardware_time_source>();
  auto dispatcher = std::make_shared<pqrs::dispatcher::dispatcher>(time_source);

  auto system_domain_target = pqrs::osx::launchctl::make_system_domain_target();
  auto gui_domain_target = pqrs::osx::launchctl::make_gui_domain_target();

  {
    pqrs::osx::launchctl::service_name service_name("org.pqrs.example");

    std::cout << "system domain-target: " << system_domain_target << std::endl;
    std::cout << "gui domain-target: " << gui_domain_target << std::endl;
    std::cout << "service-target: "
              << pqrs::osx::launchctl::make_service_target(system_domain_target, service_name)
              << std::endl;
    std::cout << "service-target: "
              << pqrs::osx::launchctl::make_service_target(gui_domain_target, service_name)
              << std::endl;
  }

  {
    pqrs::osx::launchctl::service_name service_name("com.apple.coreservicesd");
    if (auto pid = pqrs::osx::launchctl::get_pid(dispatcher,
                                                 system_domain_target,
                                                 service_name)) {
      std::cout << service_name << " pid:" << *pid << std::endl;
    }
  }

  dispatcher->terminate();
  dispatcher = nullptr;

  return 0;
}
