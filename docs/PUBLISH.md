# Initial GitHub publish

Run after installing [Git](https://git-scm.com/) and [GitHub CLI](https://cli.github.com/) (`gh auth login`).

Close Cursor/IDE windows using this folder, then rename the directory:

```powershell
Rename-Item D:\dev\motor-controller-with-encoder linko-precision-motor-controller
cd D:\dev\linko-precision-motor-controller
```

First commit and push to `ptehslai`:

```powershell
git add -A
git status
git commit -m "$( @'
Initial commit: Linko precision motor controller firmware.

Profile-based board/motor/application layering on LKS32MC45x with sensored FOC, joint_axis control, and Cyphal CAN.
'@ )"
gh repo create ptehslai/linko-precision-motor-controller --public --source=. --remote=origin --push
```

If the remote repo already exists:

```powershell
git remote add origin https://github.com/ptehsai/linko-precision-motor-controller.git
git branch -M main
git push -u origin main
```
