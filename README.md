# Tests libft

## Depuis le dossier du projet libft

Dans PowerShell, placez-vous a la racine du projet libft (le dossier qui
contient `libft.h` et le `Makefile`), puis initialisez les chemins. Choisissez
une seule ligne pour `$tests`, selon l'emplacement du dossier de tests :

```powershell
$libft = (Get-Location).Path

# Dossier de tests a cote de Libft :
$tests = "..\libft-tests-main"

# OU dossier de tests dans Libft :
# $tests = ".\libft-tests-main"
```

Adaptez le nom du dossier si necessaire. Il faut `make`, `gcc` et les outils
utilises par le Makefile de Libft. Compilez la bibliotheque :

```powershell
make
if ($LASTEXITCODE -ne 0) { throw "Compilation de Libft echouee" }
```

Verifiez ensuite les chemins :

```powershell
Test-Path "$libft\libft.h"
Test-Path "$libft\libft.a"
Test-Path "$tests\libc1.c"
```

Les trois commandes doivent afficher `True`.

## Compiler et lancer toutes les suites

La suite `bonus` necessite aussi les fonctions de listes. Compilez-les avant
de lancer toutes les suites :

```powershell
make bonus
if ($LASTEXITCODE -ne 0) { throw "Compilation du bonus echouee" }
```

```powershell
$suites = @("libc1", "libc2", "libc3", "libc4", "fs1", "fs2", "bonus")
foreach ($suite in $suites) {
    Write-Host "`n=== $suite ==="
    gcc -std=c99 -Wall -Wextra -Werror -I "$libft" "$tests\$suite.c" "$libft\libft.a" -o "$tests\$suite.exe"
    if ($LASTEXITCODE -ne 0) { throw "Compilation echouee : $suite" }
    & "$tests\$suite.exe"
    if ($LASTEXITCODE -ne 0) { throw "Execution echouee : $suite" }
}
```

Les suites affichent leurs resultats ; elles ne comparent pas toutes
automatiquement les valeurs obtenues aux valeurs attendues.

## Compiler et lancer une seule suite

Exemple avec `libc1` :

```powershell
gcc -std=c99 -Wall -Wextra -Werror -I "$libft" "$tests\libc1.c" "$libft\libft.a" -o "$tests\libc1.exe"
if ($LASTEXITCODE -eq 0) { & "$tests\libc1.exe" }
```

Si la commande indique `cannot find \libft.a`, `$libft` n'a pas ete initialise
dans la session PowerShell courante. Definissez-le comme indique plus haut,
puis relancez les commandes.
