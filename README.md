# UlamSpiralGenerator
Generates PNG files representing [Ulam Spirals](https://en.wikipedia.org/wiki/Ulam_spiral) of a desired size. Has been tested with Ulam Spirals with edges up to 35,555. Theoretically, it can support sizes up to 65,535.
## Example of Generation
#### 501 x 501 grid size (Primes up to 251,001)
![501 x 501 grid size](http://i.imgur.com/kganyFK.png)
#### 30001 x 30001 grid size (Primes up to 900,060,001)
Unfortunately, most image hosting websites compress images. On an image where each pixel represents important data, compression damages the valuable information. Therefore, I have made the output available to download. 
Click [here](https://mega.nz/#!7AAX0JYR!RQs2SikLdxKUFSgg2NFRIGy8R7XBq6VnJQc3QYuWV2E) to download the file (~83MB)
## Usage
Generate the output file for image processing.
- Compile charUlam.c 
  - `gcc -o charUlam charUlam.c Array.*`
- Run charUlam.c for a desired (odd) edge size 
  - `charUlam 5001`
- Run createSpiral.py for the same size 
  - `python createSpiral.py 5001`
