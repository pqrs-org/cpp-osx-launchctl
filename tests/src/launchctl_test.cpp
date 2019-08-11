#include <catch2/catch.hpp>

#include <pqrs/osx/launchctl.hpp>

TEST_CASE("domain_target") {
  REQUIRE(pqrs::osx::launchctl::make_system_domain_target() ==
          pqrs::osx::launchctl::domain_target("system/"));

  REQUIRE(pqrs::osx::launchctl::make_gui_domain_target(201) ==
          pqrs::osx::launchctl::domain_target("gui/201/"));

  REQUIRE(pqrs::osx::launchctl::make_gui_domain_target(501) ==
          pqrs::osx::launchctl::domain_target("gui/501/"));
}

TEST_CASE("service_target") {
  auto system_domain_target = pqrs::osx::launchctl::make_system_domain_target();
  auto gui_domain_target = pqrs::osx::launchctl::make_gui_domain_target(501);
  pqrs::osx::launchctl::service_name service_name("org.pqrs.example");

  REQUIRE(pqrs::osx::launchctl::make_service_target(system_domain_target, service_name) ==
          pqrs::osx::launchctl::service_target("system/org.pqrs.example"));

  REQUIRE(pqrs::osx::launchctl::make_service_target(gui_domain_target, service_name) ==
          pqrs::osx::launchctl::service_target("gui/501/org.pqrs.example"));
}
