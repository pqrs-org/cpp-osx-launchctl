#include <pqrs/osx/launchctl.hpp>

int main(void) {
  auto system_domain_target = pqrs::osx::launchctl::make_system_domain_target();
  auto gui_domain_target = pqrs::osx::launchctl::make_gui_domain_target();

  pqrs::osx::launchctl::service_name service_name("org.pqrs.example");

  std::cout << "system domain-target: " << system_domain_target << std::endl;
  std::cout << "gui domain-target: " << gui_domain_target << std::endl;
  std::cout << "service-target: "
            << pqrs::osx::launchctl::make_service_target(system_domain_target, service_name)
            << std::endl;
  std::cout << "service-target: "
            << pqrs::osx::launchctl::make_service_target(gui_domain_target, service_name)
            << std::endl;

  return 0;
}
