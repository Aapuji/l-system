#ifndef RULE_H
#define RULE_H

/// Represents a production rule in an L-System. 
///
/// `pred` is the predecessor pattern that is matched against; is a character.
/// `succ` is the output pattern which is emitted; is a null-terminated string.
///
/// The null byte is an invalid pattern (it will never be matched).
/// 
/// A constant (aka terminal) rule is when `pred` = `succ`. It is redundant because if the L-System 
/// comes across an unknown pattern it will treat it as a constant.
typedef struct {
    char pred;
    char *succ;
} Rule;

/// Predecessor can only be one `char`, but successor can be as many as you want (terminated by a null byte).
Rule init_rule(char predecessor, char *successor);

#endif
