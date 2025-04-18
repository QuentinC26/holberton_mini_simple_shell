#!/bin/bash

# Lire la valeur maximale de l'ID de processus
pid_max=$(cat /proc/sys/kernel/pid_max)

# Afficher la valeur
echo "La valeur maximale de l'ID de processus est : $pid_max"