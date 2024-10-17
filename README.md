# Extracting Words with "-ing" Inflection
## Edabit challenge solution

### The challenge:

Write a function that takes a string as an argument and returns a list of all the words inflected by "-ing". Your function should also exclude all the mono-syllabic words ending in "-ing" (e.g. bing, sing, sling, ...). Although these words end in "-ing", the "-ing" is not an inflection affix.

### Examples:
```
ingExtractor("coming bringing Letting sing") ➞ ["coming", "bringing", "Letting"]

ingExtractor("going Ping, king sHrink dOing") ➞ ["going", "dOing"]

ingExtractor("zing went ring, ding wing SINk") ➞ []
```

### Notes on solution:

I used the fact that I noticed the following about words with an "ing" inflection:

1. Any word > 5 letters in length would _always_ be more than one syllable
2. Any word < 5 letters would _always_ e mono-syllabic
3. A word exactly 5 letters long will be mono-syllabic if the second letter is not a vowel

### Known issues:
* Code currently does not account for punctuation - needs to remove from any words before processing