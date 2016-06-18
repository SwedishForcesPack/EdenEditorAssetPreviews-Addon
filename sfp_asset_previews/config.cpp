class CfgPatches {
  class SFP_AssetPreviews {
    requiredAddons[] = {"A3_Modules_F"};
    requiredVersion = 1.60;
    units[] = {"SFP_ModuleAssetPreviews_F"};
  };
};

class CfgFunctions {
  class SFP
  {
    class AssetPreviews
    {
      file = "\sfp_asset_previews\functions";
      class moduleAssetPreviews{

      };
    };
  };
};

class CfgVehicles {
  class Logic;
  class Module_F: Logic
  {
    class ArgumentsBaseUnits
    {
      class Units;
    };
    class ModuleDescription;
  };


  class SFP_ModuleAssetPreviews_F: Module_F
  {
    scope = 2;
    displayName = "SFP Asset Previews";
    category = "NO_CATEGORY";
    function = "sfp_fnc_moduleAssetPreviews";
    functionPriority = 1;
    isGlobal = 0;
    isPersistent = 0;
    isTriggerActivated = 0;
    isDisposable = 0;

    class ModuleDescription: ModuleDescription
    {
      description = "Triggers BIS Eden Editor Asset Previews Generator and converts images";
      sync[] = {};
    };

    class Arguments: ArgumentsBaseUnits
    {
      class Mod
      {
        displayName = "Mod";
        description = "Name of desired mod folder";
        defaultValue = "@your_mod";
      };
      class OutputPath
      {
        displayName = "Output Path";
        description = "System path where to store config.cpp and converted images";
        defaultValue = "C:\Your\Project\Folder";
      };
      class Prefix
      {
        displayName = "Prefix";
        description = "Name of desired mod folder";
        defaultValue = "\your\mod";
      };
      class ProcessImages
      {
        displayName = "Process Images";
        description = "Generate new images and copy to output directory";
        typeName = "BOOL";
        class Values
        {
          class ProcessImages {
            name = "Yes";
            value = true;
            default = 1;
          };
          class SkipProcessImages {
            name = "No";
            value = false;
          };
        };
      };
    };
  };
};
