# Tests libft

## Depuis le dossier du projet libft

Dans PowerShell, placez-vous a la racine du projet libft (le dossier qui
contient `libft.h` et le `Makefile`), puis initialisez les deux chemins avant
de lancer les tests. Exemple pour une arborescence ou `42cc` et `42\libft-tests`
sont dans le meme dossier parent :

```powershell
$libft = (Get-Location).Path
$tests = "..\42\libft-tests"
make
```

Si les tests sont dans un autre dossier, adaptez `$tests`. Verifiez les chemins
avant de compiler :

```powershell
Test-Path "$libft\libft.h"
Test-Path "$libft\libft.a"
Test-Path "$tests\libc1.c"
```

Les trois commandes doivent afficher `True`.

## Compiler et lancer toutes les suites

```powershell
$suites = @("libc1", "libc2", "libc3", "libc4", "fs1", "fs2", "bonus")
foreach ($suite in $suites) {
    Write-Host "`n=== $suite ==="
    gcc -std=c99 -Wall -Wextra -Werror -I $libft "$tests\$suite.c" "$libft\libft.a" -o "$tests\$suite.exe"
    if ($LASTEXITCODE -ne 0) { break }
    & "$tests\$suite.exe"
    if ($LASTEXITCODE -ne 0) { break }
}
```

## Compiler et lancer une seule suite

Exemple avec `libc1` :

```powershell
gcc -std=c99 -Wall -Wextra -Werror -I $libft "$tests\libc1.c" "$libft\libft.a" -o "$tests\libc1.exe"
if ($LASTEXITCODE -eq 0) { & "$tests\libc1.exe" }
```

Si la commande indique `cannot find \libft.a`, `$libft` n'a pas ete initialise
dans la session PowerShell courante. Definissez-le comme indique plus haut,
puis relancez les commandes.
