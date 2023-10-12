# How to configure an addon
1. Add an `<addon>.cpp` file with desired content
2. Create `binding.gyp` file having targets
3. For `#include<node.h>` to work, add the path having `node.h` to `include_dirs` in `binding.gyp`

# How to compile it
```
node-gyp configure
node-gyp build
```

# How to use it
1. Add an `app.js` or a similar file

# How to run it
1. Run `node app.js`
