/*  This file is part of the KDE project
    SPDX-FileCopyrightText: 2007, 2008 David Faure <faure@kde.org>

    SPDX-License-Identifier: GPL-2.0-only OR GPL-3.0-only OR LicenseRef-KDE-Accepted-GPL
*/

#ifndef MIMETYPEWRITER_H
#define MIMETYPEWRITER_H

#include <QtContainerFwd>
class QString;
class MimeTypeWriterPrivate;

/// WARNING: this code is duplicated between apps/nsplugins and runtime/filetypes

/**
 * MimeTypeWriter writes out the definition of a mimetype
 * in a XDG shared-mime-info compliant way.
 */
class MimeTypeWriter
{
public:
    MimeTypeWriter(const QString &mimeType);
    ~MimeTypeWriter();

    /**
     * Sets the comment describing this mimetype.
     * It is strongly recommended to call this.
     */
    void setComment(const QString &comment);

    /**
     * Define the patterns associated with this mimetype,
     * like "*.png"
     */
    void setPatterns(const QStringList &patterns);

    /**
     * Optional: set a user-specified icon name for this mimetype.
     * Otherwise the icon name is based on the mimetype name.
     */
    void setIconName(const QString &iconName);

    /**
     * Sets a string that will be written out as an XML comment
     * in the XML definition file, to make it possible to recognize
     * this file later on. Used by nspluginscan.
     */
    void setMarker(const QString &marker);

    /**
     * Write out the mimetype definition file
     * Returns true on success
     */
    bool write();

    /**
     * Returns true if a mimetype definition file already exists
     * for the given mimetype.
     *
     * NOTE: this is not the same as testing whether the
     * mimetype is defined in general (for instance by freedesktop.org.xml)
     * you should use db.mimeTypeForName() for that.
     * This method is only for mimetypes generated by MimeTypeWriter.
     */
    static bool hasDefinitionFile(const QString &mimeType);

    /**
     * Remove mimetype created by MimeTypeWriter.
     * Assumes hasDefinitionFile(mimeType).
     * Remember to call runUpdateMimeDatabase afterwards!
     */
    static void removeOwnMimeType(const QString &mimeType);

    /**
     * Call this once after writing as many mimetypes as you want,
     * to let update-mime-database process the new mimetype xml files.
     */
    static void runUpdateMimeDatabase();

private:
    MimeTypeWriterPrivate *const d;
};

/// WARNING: this code is duplicated between apps/nsplugins and runtime/filetypes

#endif /* MIMETYPEWRITER_H */
