/*
 *  Copyright 2017, DFKI GmbH Robotics Innovation Center
 *
 *  This file is part of the MARS simulation framework.
 *
 *  MARS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3
 *  of the License, or (at your option) any later version.
 *
 *  MARS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public License
 *   along with MARS.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MARS_DEV_YAMLSP_H
#define MARS_DEV_YAMLSP_H

#include <memory>

#include "IShaderProvider.h"
#include "configmaps/ConfigData.h"
#include "shader-function.h"
#include "ShaderFactory.h"

namespace osg_material_manager {

  using namespace std;
  using namespace configmaps;

  class YamlSP : public IShaderProvider {
  public:
    YamlSP(string res_path);

    int getMinVersion();

    const set<GLSLUniform>& getUniforms() const;

    const set<GLSLAttribute>& getVaryings() const;

    const set<string>& getEnabledExtensions() const;

    const set<string>& getDisabledExtensions() const;

    const vector<pair<string, string> >& getDependencies() const;

    const std::set<GLSLConstant>& getConstants() const;

    const std::set<GLSLAttribute>& getAttributes() const;

    string generateMainSource();

    string generateDefinitions();

    void addShaderFunction(ShaderFunc *func);

  private:
    unique_ptr<ShaderFunc> function;
  };
}


#endif //MARS_DEV_YAMLSP_H
