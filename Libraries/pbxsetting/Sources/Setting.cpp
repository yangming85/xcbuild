/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#include <pbxsetting/Setting.h>
#include <pbxsetting/Condition.h>
#include <libutil/Base.h>

using pbxsetting::Setting;
using pbxsetting::Condition;

Setting::
Setting(std::string const &name, Condition const &condition, Value const &value) :
    _name(name),
    _condition(condition),
    _value(value)
{
}

Setting::
~Setting()
{
}

bool Setting::
match(std::string const &name, Condition const &condition) const
{
    return _name == name && _condition.match(condition);
}

Setting Setting::
Create(std::string const &key, Value const &value)
{
    return Setting(key, Condition::Empty(), value);
}

Setting Setting::
Create(std::string const &key, std::string const &value)
{
    return Setting(key, Condition::Empty(), Value::String(value));
}

Setting Setting::
Parse(std::string const &string)
{
    size_t equal = 0;
    size_t sqbo  = 0;
    size_t sqbc  = 0;
    size_t comma = std::string::npos;
    std::unordered_map<std::string, std::string> conditions;

    do {
        equal = string.find('=', sqbc);
        sqbo  = string.find('[', sqbo + 1);
        sqbc  = string.find(']', sqbo);

        if (sqbo < sqbc && equal > sqbo && equal < sqbc) {
            do {
                size_t start = (comma != std::string::npos && comma > sqbo ? comma : sqbo);
                comma = string.find(',', start + 1);
                equal = string.find('=', start + 1);
                size_t end   = (comma != std::string::npos && comma < sqbc ? comma : sqbc);

                std::string key   = string.substr(start + 1, equal - start - 1);
                std::string value = string.substr(equal + 1, end - equal - 1);
                conditions.insert({ key, value });
            } while (comma != std::string::npos && comma < sqbc);
        }
    } while (sqbo < sqbc && equal > sqbo && equal < sqbc);

    sqbo = string.find('[');

    std::string key = string.substr(0, sqbo != std::string::npos ? sqbo : equal);
    std::string value = string.substr(equal + 1);

    libutil::trim(key);
    libutil::trim(value);

    return Setting(key, Condition(conditions), Value::Parse(value));
}

Setting Setting::
Parse(std::string const &key, std::string const &value)
{
    return Parse(key + "=" + value);
}
