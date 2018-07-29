#ifndef LIBRARY_COLOR_COLLECTION_H
#define LIBRARY_COLOR_COLLECTION_H

#include <set>
#include <string>

#include <Magick++.h>

namespace palette {

    // TODO: Make ColorCollection an abstract base class, from which the
    //       subclasses ColorVector and ColorSet are derived.
    class ColorCollection {
    public:
        ColorCollection();
        ColorCollection(std::vector<Magick::Color> colors);
        ColorCollection(ColorCollection &colors);

        void insert(Magick::Color color);
        void insert(std::vector<Magick::Color> colors);
        void insert(ColorCollection colors);

        typedef std::set<Magick::Color>::iterator iterator;
        typedef std::set<Magick::Color>::const_iterator const_iterator;
        iterator begin() noexcept;
        const_iterator cbegin() const noexcept;
        iterator end() noexcept;
        const_iterator cend() const noexcept;

        std::string to_string(std::string delimiter) const;
        bool empty() const;
        size_t size() const;

    private:
        std::set<Magick::Color> colors_;
    };
}

#endif // LIBRARY_COLOR_COLLECTION_H