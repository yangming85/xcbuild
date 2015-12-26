/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_Target_Environment_h
#define __pbxbuild_Target_Environment_h

#include <pbxbuild/Base.h>
#include <pbxbuild/Build/Environment.h>
#include <pbxbuild/Target/BuildRules.h>

namespace pbxbuild {

namespace Build { class Context; }

namespace Target {

class Environment {
private:
    std::shared_ptr<Target::BuildRules>      _buildRules;
    xcsdk::SDK::Target::shared_ptr           _sdk;
    std::vector<std::string>                 _specDomains;
    pbxspec::PBX::BuildSystem::shared_ptr    _buildSystem;
    pbxspec::PBX::ProductType::shared_ptr    _productType;
    pbxspec::PBX::PackageType::shared_ptr    _packageType;
    std::shared_ptr<pbxsetting::Environment> _environment;
    std::vector<std::string>                 _variants;
    std::vector<std::string>                 _architectures;
    std::string                              _workingDirectory;
    std::unordered_map<pbxproj::PBX::BuildFile::shared_ptr, std::string> _buildFileDisambiguation;

public:
    Environment();
    ~Environment();

public:
    Target::BuildRules const &buildRules() const
    { return *_buildRules.get(); }
    xcsdk::SDK::Target::shared_ptr const &sdk() const
    { return _sdk; }
    std::vector<std::string> const &specDomains() const
    { return _specDomains; }
    pbxspec::PBX::BuildSystem::shared_ptr const &buildSystem() const
    { return _buildSystem; }
    pbxspec::PBX::ProductType::shared_ptr const &productType() const
    { return _productType; }
    pbxspec::PBX::PackageType::shared_ptr const &packageType() const
    { return _packageType; }

public:
    pbxsetting::Environment const &environment() const
    { return *_environment; }
    std::vector<std::string> const &variants() const
    { return _variants; }
    std::vector<std::string> const &architectures() const
    { return _architectures; }

public:
    std::string const &workingDirectory() const
    { return _workingDirectory; }
    std::unordered_map<pbxproj::PBX::BuildFile::shared_ptr, std::string> const &buildFileDisambiguation() const
    { return _buildFileDisambiguation; }

public:
    static std::unique_ptr<Environment>
    Create(Build::Environment const &buildEnvironment, pbxproj::PBX::Target::shared_ptr const &target, Build::Context const *context);
};

}
}

#endif // !__pbxbuild_Target_Environment_h
