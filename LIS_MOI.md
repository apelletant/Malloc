du coup j'ai fini le malloc
j'ai pas test je sais pas si il fonctionne

ya 2/3 truc tricky comme le truc pour aligner les pointeurs
et le coup char[1] (en gros sa store les données dans un char pour avoir
une précision a l'octet pres)

lien du tuto que j'ai suivi si tu comprend pas tout je t'expliquerai
http://www.inf.udec.cl/~leo/Malloc_tutorial.pdf
dans le tuto il fais du biteshift pour aligner les pointer,
mais j'ai trouvé une formule mathematique qui fais pareil
normalement j'ai pas test donc jpeux pas te dire

j'ai changé 3/4 truc pour pas que sa y ressemble
mais sa y ressemble pas mal quand meme
si tu veux t'amuser a changer des truc pour modifier les ressemblablités
(oui je sais ça se dis pas mdr) amuses toi!! :D

tu peux faire le calloc si sa t'amuse
c'est un malloc plus un memset du coup Lisa facil (MDRRRRRR je suis trop drole)
vu que faut pas recoder memset

normalement le show mem alloc fonctione aussi. Faut juste check le flag %zu
c'est pour print des size_t sauf que je sais pas si on y a le droit si on doit
compiler en C99 c'est bon sinon faudra trouver autre chose

Voila bisous