//
// Created by Mykhailo Burenko on 2/6/21.
//

#ifndef OWN_UCHAT_UTILS_DEFINE_H
#define OWN_UCHAT_UTILS_DEFINE_H

#define CREATE_STRUCT(type) (struct type *) malloc(sizeof (struct type));
#define CREATE(type) (type *) malloc(sizeof (type));
#define CREATE_SIZE(type,size) (type *) malloc(size * sizeof (type));
#define when(predicate, code) case predicate: code break;
#define FOR(start , finish) for(int i = start; i < finish; i++)
#define FOR_N(name,start , finish) for(int name = start; name < finish; name++)

#endif //OWN_UCHAT_UTILS_DEFINE_H
