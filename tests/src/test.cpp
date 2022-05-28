#include <boost/ut.hpp>
#include <pqrs/osx/launchctl.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "domain_target"_test = [] {
    expect(pqrs::osx::launchctl::make_system_domain_target() ==
           pqrs::osx::launchctl::domain_target("system/"));

    expect(pqrs::osx::launchctl::make_gui_domain_target(201) ==
           pqrs::osx::launchctl::domain_target("gui/201/"));

    expect(pqrs::osx::launchctl::make_gui_domain_target(501) ==
           pqrs::osx::launchctl::domain_target("gui/501/"));
  };

  "service_target"_test = [] {
    auto system_domain_target = pqrs::osx::launchctl::make_system_domain_target();
    auto gui_domain_target = pqrs::osx::launchctl::make_gui_domain_target(501);
    pqrs::osx::launchctl::service_name service_name("org.pqrs.example");

    expect(pqrs::osx::launchctl::make_service_target(system_domain_target, service_name) ==
           pqrs::osx::launchctl::service_target("system/org.pqrs.example"));

    expect(pqrs::osx::launchctl::make_service_target(gui_domain_target, service_name) ==
           pqrs::osx::launchctl::service_target("gui/501/org.pqrs.example"));
  };

  return 0;
}
