#include "Playlist.hpp"

#include <algorithm>

namespace ProjectM {
namespace Playlist {

uint32_t Playlist::Size() const
{
    return 0;
}


void Playlist::Clear()
{
}


const std::vector<Item>& Playlist::Items()
{
    return m_items;
}


bool Playlist::AddItem(const std::string& filename, uint32_t index, bool allowDuplicates)
{
    if (!allowDuplicates)
    {
        if (std::find(m_items.begin(), m_items.end(), filename) != m_items.end())
        {
            return false;
        }
    }

    if (index >= m_items.size())
    {
        m_items.emplace_back(filename);
    }
    else
    {
        m_items.emplace(m_items.cbegin() + index, filename);
    }

    return true;
}


auto Playlist::RemoveItem(uint32_t index) -> bool
{
    if (index >= m_items.size())
    {
        return false;
    }

    m_items.erase(m_items.cbegin() + index);

    return true;
}


void Playlist::Shuffle(bool enabled)
{
    m_shuffle = enabled;
}

} // namespace Playlist
} // namespace ProjectM