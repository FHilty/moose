/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef COMMONOUTPUTACTION_H
#define COMMONOUTPUTACTION_H

// MOOSE includes
#include "Action.h"

// Forward declerations
class CommonOutputAction;
class OutputWarehouse;

template<>
InputParameters validParams<CommonOutputAction>();

/**
 * Meta-action for creating common output object parameters
 * This action serves two purpose, first it adds common output object
 * parameters. Second, it creates the action (AddOutputAction) short-cuts
 * such as 'exodus=true' that result in the default output object of that
 * type to be created.
 * */
class CommonOutputAction: public Action
{
public:

  /**
   * Class constructor
   */
  CommonOutputAction(const std::string & name, InputParameters params);

  /**
   * Perform the action creation
   */
  virtual void act();

private:

  /**
   * Helper method for creating the short-cut actions
   * @param object_type String of the object type, i.e., the value of 'type=' in the input file
   */
  void create(std::string object_type);

  /**
   * Helper method for creating Checkpoint object for auto recovery testing
   */
  void createAutoRecoveryCheckpointObject();

  /**
   * Set the file base for recovery
   */
  void setRecoverFileBase();

  /**
   * Extract the recovery directory
   * @return A string containing the default recovery directory
   */
  std::string getRecoveryDirectory();

  /**
   * Check if a Console object that outputs to the screen has been defined
   * @return True if the a screen outputting Console objects
   */
  bool hasConsole();

  /// Parameters from the action being created (AddOutputAction)
  InputParameters _action_params;
};

#endif //COMMONOUTPUTACTION_H
