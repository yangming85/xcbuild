/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxspec_PBX_ProductType_h
#define __pbxspec_PBX_ProductType_h

#include <pbxsetting/pbxsetting.h>
#include <pbxspec/PBX/Specification.h>

#include <ext/optional>

namespace pbxspec { namespace PBX {

class ProductType : public Specification {
public:
    typedef std::shared_ptr <ProductType> shared_ptr;
    typedef std::vector <shared_ptr> vector;

public:
    class Validation {
    public:
        class Check {
        private:
            ext::optional<std::string> _check;
            ext::optional<std::string> _description;

        protected:
            friend class Validation;
            Check(ext::optional<std::string> const &check, ext::optional<std::string> const &description);

        public:
            inline ext::optional<std::string> const &check() const
            { return _check; }
            inline ext::optional<std::string> const &description() const
            { return _description; }
        };

    protected:
        friend class Check;

    private:
        ext::optional<std::string>        _validationToolSpec;
        ext::optional<std::vector<Check>> _checks;

    protected:
        friend class ProductType;
        Validation();

    public:
        inline ext::optional<std::string> const &validationToolSpec() const
        { return _validationToolSpec; }

    public:
        inline ext::optional<std::vector<Check>> const &checks() const
        { return _checks; }

    protected:
        bool parse(plist::Dictionary const *dict);
    };

protected:
    friend class Validation;

protected:
    ext::optional<std::string>              _defaultTargetName;
    ext::optional<pbxsetting::Level>        _defaultBuildProperties;
    ext::optional<Validation>               _validation;
    ext::optional<std::vector<std::string>> _packageTypes;
    ext::optional<std::string>              _iconNamePrefix;
    ext::optional<bool>                     _hasInfoPlist;
    ext::optional<bool>                     _hasInfoPlistStrings;
    ext::optional<bool>                     _isWrapper;
    ext::optional<bool>                     _isJava;
    ext::optional<bool>                     _supportsZeroLink;
    ext::optional<bool>                     _alwaysPerformSeparateStrip;
    ext::optional<bool>                     _wantsSimpleTargetEditing;
    ext::optional<bool>                     _addWatchCompanionRequirement;
    ext::optional<bool>                     _runsOnProxy;
    ext::optional<bool>                     _disableSchemeAutocreation;
    ext::optional<bool>                     _validateEmbeddedBinaries;
    ext::optional<bool>                     _supportsOnDemandResources;
    ext::optional<bool>                     _canEmbedAddressSanitizerLibraries;
    ext::optional<std::string>              _runpathSearchPathForEmbeddedFrameworks;

protected:
    ProductType();

public:
    virtual ~ProductType();

public:
    inline char const *type() const override
    { return ProductType::Type(); }

public:
    inline ProductType::shared_ptr const &base() const
    { return reinterpret_cast <ProductType::shared_ptr const &> (Specification::base()); }

public:
    inline ext::optional<std::string> const &defaultTargetName() const
    { return _defaultTargetName; }

public:
    inline ext::optional<pbxsetting::Level> const &defaultBuildProperties() const
    { return _defaultBuildProperties; }

public:
    inline ext::optional<Validation> const &validation() const
    { return _validation; }

public:
    inline ext::optional<std::vector<std::string>> const &packageTypes() const
    { return _packageTypes; }

public:
    inline ext::optional<std::string> const &iconNamePrefix() const
    { return _iconNamePrefix; }

public:
    inline bool hasInfoPlist() const
    { return _hasInfoPlist.value_or(false); }
    inline ext::optional<bool> hasInfoPlistOptional() const
    { return _hasInfoPlist; }
    inline bool hasInfoPlistStrings() const
    { return _hasInfoPlistStrings.value_or(false); }
    inline ext::optional<bool> hasInfoPlistStringsOptional() const
    { return _hasInfoPlistStrings; }

public:
    inline bool isWrapper() const
    { return _isWrapper.value_or(false); }
    inline ext::optional<bool> isWrapperOptional() const
    { return _isWrapper; }

public:
    inline bool isJava() const
    { return _isJava.value_or(false); }
    inline ext::optional<bool> isJavaOptional() const
    { return _isJava; }

public:
    inline bool supportsZeroLink() const
    { return _supportsZeroLink.value_or(false); }
    inline ext::optional<bool> supportsZeroLinkOptional() const
    { return _supportsZeroLink; }

public:
    inline bool alwaysPerformSeparateStrip() const
    { return _alwaysPerformSeparateStrip.value_or(false); }
    inline ext::optional<bool> alwaysPerformSeparateStripOptional() const
    { return _alwaysPerformSeparateStrip; }

public:
    inline bool wantsSimpleTargetEditing() const
    { return _wantsSimpleTargetEditing.value_or(false); }
    inline ext::optional<bool> wantsSimpleTargetEditingOptional() const
    { return _wantsSimpleTargetEditing; }

public:
    inline bool addWatchCompanionRequirement() const
    { return _addWatchCompanionRequirement.value_or(false); }
    inline ext::optional<bool> addWatchCompanionRequirementOptional() const
    { return _addWatchCompanionRequirement; }

public:
    inline bool runsOnProxy() const
    { return _runsOnProxy.value_or(false); }
    inline ext::optional<bool> runsOnProxyOptional() const
    { return _runsOnProxy; }

public:
    inline bool disableSchemeAutocreation() const
    { return _disableSchemeAutocreation.value_or(false); }
    inline ext::optional<bool> disableSchemeAutocreationOptional() const
    { return _disableSchemeAutocreation; }

public:
    inline bool validateEmbeddedBinaries() const
    { return _validateEmbeddedBinaries.value_or(false); }
    inline ext::optional<bool> validateEmbeddedBinariesOptional() const
    { return _validateEmbeddedBinaries; }

public:
    inline bool supportsOnDemandResources() const
    { return _supportsOnDemandResources.value_or(false); }
    inline ext::optional<bool> supportsOnDemandResourcesOptional() const
    { return _supportsOnDemandResources; }

public:
    inline bool canEmbedAddressSanitizerLibraries() const
    { return _canEmbedAddressSanitizerLibraries.value_or(false); }
    inline ext::optional<bool> canEmbedAddressSanitizerLibrariesOptional() const
    { return _canEmbedAddressSanitizerLibraries; }

public:
    inline ext::optional<std::string> const &runpathSearchPathForEmbeddedFrameworks() const
    { return _runpathSearchPathForEmbeddedFrameworks; }

protected:
    friend class Specification;
    bool parse(Context *context, plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check) override;

protected:
    bool inherit(Specification::shared_ptr const &base) override;
    virtual bool inherit(ProductType::shared_ptr const &base);

protected:
    static ProductType::shared_ptr Parse(Context *context, plist::Dictionary const *dict);

public:
    static inline char const *Type()
    { return Types::ProductType; }
};

} }

#endif  // !__pbxspec_PBX_ProductType_h
