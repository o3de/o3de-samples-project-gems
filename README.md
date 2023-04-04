# O3DE Samples Project Gems

( replace with readme header image )

This repository contains:

1. A collection of O3DE Asset Gems (portable asset packages)
   1. The source folder for each Gem, for development by Contributors.
   2. E.g. an Asset Gem for Bistro converter for use in O3DE
2. Asset test projects in: o3de-samples-project-gems/tree/main/Projects/*
3. (Future) A `repo.json` file containing information about this O3DE Remote Gem Repository
4. (Future) A GitHub release folder
   1. The gem .zip containing the gem and associated gem.json for each gem

## If you want to use these Gems in your own o3de game project

### (Future) Option #1. Remote Repository, use packaged Gems with the Project Manager

**!!! Skip to Option #2 !!!**

**<u>Use of this as a remote gem repository is not yet implemented!</u>**

Add this remote repository in the Project Manager using this URL:

```
https://raw.githubusercontent.com/AMZN-temp-user-replace-me/o3de-remote-gem-repo-demo/main
```

You can then browse the gems in the Project Manager and add them to your Project.

### Option #2.  Download and use source Gems

You can clone this repo to download the repository source, then register the local gem source folders with the engine to make available for use in a Project. This entails the same steps as a developer contributing content creation or performing other maintenance of the gem data. (see the next section below.)

## If you are a developer contributing to these asset gems

### Download and Install

This repository uses Git LFS for storing large binary files. You will need to create a Github personal access token to authenticate with the LFS service.

#### Create a Git Personal Access Token

You will need your personal access token credentials to authenticate when you clone the repository.

[Create a personal access token with the 'repo' scope.](https://docs.github.com/en/github/authenticating-to-github/creating-a-personal-access-token)

#### (Recommended) Verify you have a credential manager installed to store your credentials

Recent versions of Git install a credential manager to store your credentials so you don't have to put in the credentials for every request. It is highly recommended you check that you have a [credential manager installed and configured](https://github.com/microsoft/Git-Credential-Manager-Core)

#### Step 1. Clone the repository

You can clone the project to any folder locally, including inside the engine folder. If you clone the repository inside an existing Git repository (e.g. o3de) you should add the project folder to the Git exclude file for the existing repository.

##### Option #1 (Highly Recommended) - cloning into a folder outside the engine repository folder

```shell
# clone the project into a folder outside your engine repository folder
> git clone https://github.com/o3de/o3de-samples-project-gems.git
Cloning into 'o3de-samples-project-gems'...
```

##### Option #2 - cloning into the engine repository folder

```shell
# clone the project into a folder named 'o3de-multiplayersample' in your existing engine repository folder
> git clone https://github.com/o3de/o3de-samples-project-gems.git c:/path/to/o3de/Gems/o3de-samples-project-gems
Cloning into 'o3de-samples-project-gems'...

# modify the local engine git exclude file to ignore the project folder
> echo gems\o3de-multiplayersample-assets > c:/path/to/o3de/.git/info/exclude
```

If you have a Git credential helper configured, you should not be prompted for your credentials anymore.

### Step 2. Register the gems with the engine

You may have already done this, these are the same steps as setting up the o3de-multiplayer sample project. But if you are adding them to your own project these are the steps to do so.

Make sure your engine is registered.

```batch
:: register the gems with the engine, you only need to do this once
> C:\path\to\o3de\scripts\o3de register --this-engine
```

Make sure your project is registered.

```batch
:: register the project with the engine, you only need to do this once
> C:\path\to\o3de\scripts\o3de register -p C:\path\to\o3de-samples-project-gems\Projects\BistroPBR
```

Now make sure that the source gems are registered

```batch
:: register the gems with the engine, you only need to do this once
> o3de register --all-gems-path C:\path\to\o3de-samples-project-gems\Gems
```

The above command will recursively scan the input path, then registers all paths with gem.json files into the `~/.o3de/o3de_manifest.json`

Now these Gems will be available in the Project Manager and can be added to your Project.

## (Optional) o3de-samples-project-gems\Projects\*

This repository contains it's own O3DE Game projects which utilize these sample assets.  These projects can be used by contributors to build, validate, and maintain new assets independently.

```shell
# the test project for mps assets, is in this project folder in repo
> cd C:\path\to\o3de-samples-project-gems\Project
```

### Option 1. Add Project to O3DE Project Manager

1. Launch your O3DE Project Manager (o3de.exe)

2. Use the blue button in the upper right labeled "New Project ...", and with the pulldown select "Open Existing Project"

3. Browse to and add the MPS Asset Test Project folder: `C:\path\to\repo\o3de-samples-project-gems\Projects\<sample project>`

4. You may be prompted to rebuild the project (there are other options for building as a developer)

5. Launch the Editor for the project

### Option 2. Add via cli and build yourself

You can use the o3de cli tools to register your project with your engine.

```shell
# change directory to the engine root folder
> cd C:\path\to\your\o3de-engine
# register the gems with the engine, you only need to do this once
> scripts\o3de register --project-path C:\depot\o3de-samples-project-gems\Projects\<sample project>
```

There are a number of ways to configure and build the engine and project ...

[Configure and Build - Open 3D Engine](https://www.o3de.org/docs/user-guide/build/configure-and-build/)

## Contributing to O3DE-samples-project-gems Repo

After following all the steps above, you should be ready to start working. Once you are in the Editor, you can develop assets to be committed to the asset repo. Working with the o3de-samples-project-gems repo is a similar workflow to the o3de codebase, the general git contributor guide is here for reference: https://docs.o3de.org/docs/contributing/to-code/git-workflow/

The main O3DE contributor guide is here:

[Contribute to Open 3D Engine - Open 3D Engine](https://www.o3de.org/contribute/#contribution-guidelines)

And the CONTRIBUTING guide for this asset repo has additional information regarding best practices for developing and contributing assets such as 3D models, texture images and materials, characters and animations, etc.:

[o3de-samples-project-gems/CONTRIBUTING.md](https://github.com/o3de/o3de-samples-project-gems/blob/main/CONTRIBUTING.md)

# Appendix

How these Asset Gems were made with O3DE:

1. The Gems were created from the [O3DE AssetGem Template](https://github.com/o3de/o3de/tree/development/Templates/AssetGem)

2. Then the `gem.json` (metadata) was manually updated per-gem in a text editor to customize the information to display when browsing and viewing the Gems from the O3DE project manager.

```batch
cd c:\path\to\o3de\
scripts\o3de create-gem --gem-path C:\path\to\o3de-samples-project-gems\Gems\my_gem --template-path C:\path\to\o3de\Templates\AssetGem
```

## License

For terms please see the LICENSE*.TXT file at the root of this distribution.