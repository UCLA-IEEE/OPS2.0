# OPS2.0

Here you can find the official website for OPS2.0! The website uses the Jekyll framework, which
conveniently transforms Markdown pages into blog-style articles.

Before you launch the website, make sure to follow the Jekyll installation guide [here](https://jekyllrb.com/docs/installation/). You will need to have Ruby and Bundler installed.

The root directory of the website is `docs`. Navigate into `docs` in your terminal and run the following command to deploy the website to your local web server.
```
bundle exec jekyll serve
```
Now, the website should be up and running on http://localhost:4000/OPS2.0/.

In order to modify general information that applies to the entire site, modify `_config.yml`. This includes information such as author details, social links, website configurations, etc. Note that the server must be restarted in order to reflect these changes.

In order to add a new webpage, navigate to the `_pages` directory and create a markdown file (with extension ".md"). Add the following header:
```
title: "Red Light, Green Light Game"
permalink: /redlight-greenlight/
last_modified_at: 2020-05-14T14:07:54-04:00
toc: true
```
This information is fairly self explanatory. `toc` stands for Table of Contents, so make sure to set this to true if you are writing a project spec or other lengthy document. Now, the page can be accessed at http://localhost:4000/OPS2.0/yourpermalinkhere/.

Lastly, we'll need to add the page to the navbar that is at the top of every page. Open `/_data/navigation.yml/` and add your page under the `main` section of links. Now, resetting the website should result in your page appearing in the navbar!
