params ["_logic"];

_mod = _logic getVariable "Mod";
_outputPath = _logic getVariable "OutputPath";
_prefix = _logic getVariable "Prefix";
_processImages = _logic getVariable "ProcessImages";

_extension = "EdenEditorAssetPreviews";
_extension callExtension "init";

_extension callExtension format ["setMod;%1", _mod];
_extension callExtension format ["setOutputPath;%1", _outputPath];
_extension callExtension format ["setPrefix;%1", _prefix];
_extension callExtension format ["setProfileName;%1", profileName];

_vehicles = "getNumber (_x >> 'scope') == 2" configClasses (configFile >> "CfgVehicles");
_patches = [];

{
  _config = _x;

  if (configSourceMod _config == _mod) then {
    _inheritsFrom = configName inheritsFrom _config;
    _name = configName _config;

    {
      if (_patches find _x < 0) then {
        _patches pushBack _x;
        _extension callExtension format ["addAddon;%1", _x];
      };
    } forEach configSourceAddonList _config;

    _extension callExtension format ["addClass;%1;%2", _name, _inheritsFrom];
  };
} forEach _vehicles;

[_extension, _patches, _processImages] spawn {
  params ["_extension", "_patches", "_processImages"];

  if (_processImages) then {
    {
      0 = [0.5, "all", [], [], [_x]] call BIS_fnc_exportEditorPreviews;
      _extension callExtension "processImages";
    } forEach _patches;
  };

  _extension callExtension "processConfig";

  hint "Done!";
};
