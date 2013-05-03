/* 
 * File:   Table.cpp
 * Author: Gab
 * 
 * Created on 24 de Janeiro de 2013, 02:02
 */

#include <Plus.hpp>

namespace Plus {
        /*
         * Create a 1-dimensional table
         * 
         * @param unsigned long Size
         * @return Plus::Table New table
         */
        Table::Table(unsigned long xsize){
            this->dimensions = 1;
            this->xsize = xsize;
            this->ysize = 1;
            this->zsize = 1;
        }
        
        /*
         * Create a 2-dimensional table
         * 
         * @param unsigned long Horizontal size
         * @param unsigned long Vertical size
         * @return Plus::Table New table
         */
        Table::Table(unsigned long xsize, unsigned long ysize){
            this->dimensions = 2;
            this->xsize = xsize;
            this->ysize = ysize;
            this->zsize = 1;
        }
        
        /*
         * Create a 3-dimensional table
         * 
         * @param unsigned long X size
         * @param unsigned long Y size
         * @param unsigned long Z size
         * @return PLus::Table New Table
         */
        Table::Table(unsigned long xsize, unsigned long ysize, unsigned long zsize){
            this->dimensions = 3;
            this->xsize = xsize;
            this->ysize = ysize;
            this->zsize = zsize;
        }
        
        /*
         * Resize table to an 1-dimensional x sized table. All data within the
         * resize limits won't be touched.
         * 
         * @param unsigned long New x size
         * @return void
         */
        void Table::resize(unsigned long xsize){
            this->dimensions = 1;
            this->xsize = xsize;
            this->ysize = 1;
            this->zsize = 1;
        }
        
        /*
         * Resize table to an 2-dimensional x by y sized table. All data within 
         * the resize limits won't be touched.
         * 
         * @param unsigned long New x size
         * @param unsigned long New y size
         * @return void
         */
        void Table::resize(unsigned long xsize, unsigned long ysize){
           this->dimensions = 2; 
           this->xsize = xsize;
           this->ysize = ysize;
           this->zsize = 1;
        }
        
        /*
         * Resize table to an 2-dimensional x by y by z b sized table. All data 
         * within the resize limits won't be touched.
         * 
         * @param unsigned long New x size
         * @param unsigned long New y size
         * @param unsigned long New z size
         * @return void
         */
        void Table::resize(unsigned long xsize, unsigned long ysize, unsigned long zsize){
            this->dimensions = 3;
            this->xsize = xsize;
            this->ysize = ysize;
            this->zsize = zsize;
        }
        
        /*
         * Get the x(th) element on the table (for 1-dimensional)
         * 
         * @param unsigned long X position
         * @return unsigned short Element
         */
        unsigned short Table::get(unsigned long x){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 1){
            #endif
                    return 0; // TODO - Get and return value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                } else {
                    return 0;
                }
            #endif
        }
        
        /*
         * Get the x(th) element on the y(th) row of the table (for 2-dimensional)
         * 
         * @param unsigned long X position
         * @param unsigned long Y position
         * @return unsigned short Element
         */
        unsigned short Table::get(unsigned long x, unsigned long y){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 2){
            #endif
                    return 0; // TODO - Get and return value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                } else {
                    return 0;
                }
            #endif
        }
        
        /*
         * Get the x(th) element on the y(th) row on the z(th) plane of the 
         * table (for 3-dimensional)
         * 
         * @param unsigned long X position
         * @param unsigned long Y position
         * @param unsigned long Z position
         * @return unsigned short Element
         */
        unsigned short Table::get(unsigned long x, unsigned long y, unsigned long z){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 3){
            #endif
                    return 0; // TODO - Get and return value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                } else {
                    return 0;
                }
            #endif
        }
        
        /*
         * Set the x(th) element on the table (for 1-dimensional)
         * 
         * @param unsigned long X position
         * @param unsigned short New value
         * @return void
         */
        void Table::set(unsigned long x, unsigned short value){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 1){
            #endif
                    // TODO - Set value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                }
            #endif
        }
        
        /*
         * Get the x(th) element on the y(th) row of the table (for 2-dimensional)
         * 
         * @param unsigned long X position
         * @param unsigned long Y position
         * @param unsigned short New value
         * @return void
         */
        void Table::set(unsigned long x, unsigned long y, unsigned short value){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 2){
            #endif
                    // TODO - Set value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                }
            #endif
        }
        
        /*
         * Get the x(th) element on the y(th) row on the z(th) plane of the 
         * table (for 3-dimensional)
         * 
         * @param unsigned long X position
         * @param unsigned long Y position
         * @param unsigned long Z position
         * @param unsigned short New value
         * @return void
         */
        void Table::set(unsigned long x, unsigned long y, unsigned long z, unsigned short value){
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                if (this->dimensions == 3){
            #endif
                    // TODO - Set value
            #if PLUS_TABLE_ENABLE_DIM_CHECK
                }
            #endif
        }
        
        /*
         * Simplify table in a structure
         * 
         * @return Plus::Table::packedTable Packed table data
         */
        Table::packedTable Table::dump(){
            packedTable pack;
            pack.dim     = this->dimensions;
            pack.xsize   = this->xsize;
            pack.ysize   = this->ysize;
            pack.zsize   = this->zsize;
            pack.memSize = this->xsize * this->ysize * this->zsize;
            // TODO: Fill data 
            return pack;
        }
        
        /*
         * Load packed table data
         * 
         * @param Plus::Table::packedTone Packed tone data
         * @return void
         */
        void Table::load(Table::packedTable packed){
            this->dimensions = packed.dim;
            this->xsize      = packed.xsize;
            this->ysize      = packed.ysize;
            this->zsize      = packed.zsize;
            
            // TODO: Fill table data with packed.data
        }

        /*
         * Destructor
         */
        Table::~Table(){
            
        }
};

