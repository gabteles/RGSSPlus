#ifndef PLUS_TABLE_HPP
#define	PLUS_TABLE_HPP

namespace Plus {
    class Table {
        struct packedTable {
            unsigned long dim;
            unsigned long xsize;
            unsigned long ysize;
            unsigned long zsize;
            unsigned long memSize;
            unsigned short* data;
        };

    public:
        Table(unsigned long xsize);
        Table(unsigned long xsize, unsigned long ysize);
        Table(unsigned long xsize, unsigned long ysize, unsigned long zsize);
        void resize(unsigned long xsize);
        void resize(unsigned long xsize, unsigned long ysize);
        void resize(unsigned long xsize, unsigned long ysize, unsigned long zsize);
        unsigned short get(unsigned long x);
        unsigned short get(unsigned long x, unsigned long y);
        unsigned short get(unsigned long x, unsigned long y, unsigned long z);
        void set(unsigned long x, unsigned short value);
        void set(unsigned long x, unsigned long y, unsigned short value);
        void set(unsigned long x, unsigned long y, unsigned long z, unsigned short value);
        packedTable dump();
        void load(packedTable packed);
        ~Table();

    private:
        unsigned char dimensions;
        unsigned long xsize, ysize, zsize;
    };
};

#endif	/* PLUS_TABLE_HPP */

