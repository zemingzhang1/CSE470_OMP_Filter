!/bin/bash

###### PLANEX SPECIFIC - DO NOT EDIT THIS SECTION
SBATCH --clusters=faculty
SBATCH --partition=planex
SBATCH --qos=planex
SBATCH --account=cse570f21
SBATCH --exclusive
SBATCH --mem=64000
SBATCH --output=%j.stdout
SBATCH --error=%j.stderr

###### CUSTOMIZE THIS SECTION FOR YOUR JOB
SBATCH --job-name="changeme"
SBATCH --nodes=1
SBATCH --ntasks-per-node=20
SBATCH --time=01:00:00

your app invocation should follow
