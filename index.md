## Welcome to I/O FUNCTIONS LIST

You can use the [editor on GitHub](https://github.com/chronosss1/pruebaweb/edit/master/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# titulo
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/chronosss1/pruebaweb/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.


# STDIO


## printf:
int printf : (const char *, ...);

Description:
The function printf() write in the screen the strings introduced in the input.  
It returns an int, if it worked correctly it returns 0 if not it returns -1.


## fprintf:
fprintf(FILE * stream,char *, ...);

Description:
The function fprintf() write in the stream given the strings introduced in the input.  
It returns an int, if it worked correctly it returns 0 if not it returns -1.


## perror:

perror(const char * s)

Description:
It prints the strings s followed by the error corresponding to the value of errno in that moment.  
It does not return anything.


## perror:

int scanf(const char * format, char *)  
`La funcion tiene los argumentos simplificados(en la original son varios) hay que decidir si simplificarlo o mantener varios`

Description:
It reads from the standard input to the char pointer indicated as 2º argument.  
It returns 0 in success or -1 if not.
