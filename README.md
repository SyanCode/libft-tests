# Tests libft

Les commandes ci-dessous sont a lancer dans PowerShell, depuis le dossier
`libft-tests`. Elles supposent que le projet `libft` se trouve dans le dossier
voisin `..\libft`. Modifiez `$libft` si votre projet se trouve ailleurs.

## Compiler la libft

```powershell
$libft = "..\libft"
make -C $libft
```

## Compiler et lancer toutes les suites

```powershell
$suites = @("libc1", "libc2", "libc3", "libc4", "fs1", "fs2", "bonus")
foreach ($suite in $suites) {
    Write-Host "`n=== $suite ==="
    gcc -std=c99 -Wall -Wextra -Werror -I $libft "$suite.c" "$libft\libft.a" -o "$suite.exe"
    if ($LASTEXITCODE -ne 0) { break }
    & ".\$suite.exe"
    if ($LASTEXITCODE -ne 0) { break }
}
```

## Lancer une seule suite

Exemple avec `libc1` :

```powershell
$libft = "..\libft"
gcc -std=c99 -Wall -Wextra -Werror -I $libft libc1.c "$libft\libft.a" -o libc1.exe
if ($LASTEXITCODE -eq 0) { .\libc1.exe }
```

Les suites affichent leurs fonctions par sections et indiquent les valeurs
attendues. Il faut comparer les resultats affiches aux valeurs attendues.
