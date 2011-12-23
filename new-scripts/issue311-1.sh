#! /bin/bash

CONFIGS=lamalike_configs.py:lamalike_unit

### For the real experiment, use this:
SUITE=SATISFICING_UNIT_COST
EXPTYPE=gkigrid
QUEUE=all.q

### For testing, use this:
#SUITE=gripper:prob01.pddl,gripper:prob02.pddl
#EXPTYPE=local


EXPOPTS=--compact
export DOWNWARD_TIMEOUT=1800

source experiment.sh
